#pragma once
#ifndef PI
#define PI  3.14159265358979323846
#endif

const int NumTimesToSubdivide = 5;
const int num_tri = 4096;
const int num_vertexes = 3 * num_tri;
int tri_index = 0;
int cylinder_vertexes = 600;
int TextureWidth[3];
int TextureHeight[3];
int moveObject = 0;
int curx, cury;
int pFlag = 1; //toggle object flag if picked 


typedef Angel::vec4 point4;
typedef Angel::vec4 color4;

Angel::vec4 eye = vec4(0.0, 1.5, 3.0, 1.0);
Angel::vec4 v = vec4(0.0, 1.0, 0.0, 00);
Angel::vec4 u = vec4(1.0, 0.0, 0.0, 0.0);
Angel::vec4 n = Angel::normalize(vec4(0.0, 0.0, 1.0, 0.0));

point4 points[num_vertexes];
vec3   normals[num_vertexes];
vec2   tex_coords[num_vertexes];

point4 scene_light_pos(4.0, 0.0, 1.0, 0.0);
float spin = 0.0, spin_step = 0.001;
float  material_shininess;

point4 cylinderData[600];

GLuint  ModelView, Projection, NormalTransformation, ModelViewObj, vPosition, vNormal, vColor, vTexCoord;
GLuint textures[3];
GLuint program[3];
GLuint buffers[9];
GLuint vao[3];

GLubyte* image0;
GLubyte* image1;
GLubyte* image2;

void make_sphere(void);
void paint_sphere(void);
void make_cylinder(void);
void paint_cylinder(void);
void paint_ellipse(void);

vec4 productComponentwise(vec4 a, vec4 b)
{
	return vec4(a[0] * b[0], a[1] * b[1], a[2] * b[2], a[3] * b[3]);
}


void
triangle(const point4& a, const point4& b, const point4& c)
{
	normals[tri_index] = normalize(vec3(a[0], a[1], a[2]));  points[tri_index] = a;  tex_coords[tri_index] = vec2(a[2], a[1]); tri_index++;
	normals[tri_index] = normalize(vec3(b[0], b[1], b[2]));  points[tri_index] = b;  tex_coords[tri_index] = vec2(b[2], b[1]); tri_index++;
	normals[tri_index] = normalize(vec3(c[0], c[1], c[2]));  points[tri_index] = c;  tex_coords[tri_index] = vec2(c[2], c[1]); tri_index++;
}


point4
unit(const point4& p)
{
	float len = p.x*p.x + p.y*p.y + p.z*p.z;

	point4 t;
	if (len > DivideByZeroTolerance) {
		t = p / sqrt(len);
		t.w = 1.0;
	}

	return t;
}

void divide_triangle(const point4& a, const point4& b,
	const point4& c, int number)
{
	if (number > 0) {
		point4 v1 = unit(a + b);
		point4 v2 = unit(a + c);
		point4 v3 = unit(b + c);
		divide_triangle(a, v1, v2, number - 1);
		divide_triangle(c, v2, v3, number - 1);
		divide_triangle(b, v3, v1, number - 1);
		divide_triangle(v1, v3, v2, number - 1);
	}
	else {
		triangle(a, b, c);
	}
}


void
tetrahedron(int number)
{
	point4 v[4] = {
		vec4(0.0, 0.0, 1.0, 1.0),
		vec4(0.0, 0.942809, -0.333333, 1.0),
		vec4(-0.816497, -0.471405, -0.333333, 1.0),
		vec4(0.816497, -0.471405, -0.333333, 1.0)
	};

	divide_triangle(v[0], v[1], v[2], number);
	divide_triangle(v[3], v[2], v[1], number);
	divide_triangle(v[0], v[3], v[1], number);
	divide_triangle(v[0], v[2], v[3], number);
}


class MatrixStack {
	int    _index;
	int    _size;
	mat4*  _matrices;

public:
	MatrixStack(int numMatrices = 32) :_index(0), _size(numMatrices)
	{
		_matrices = new mat4[numMatrices];
	}

	~MatrixStack()
	{
		delete[]_matrices;
	}

	void push(const mat4& m) {
		assert(_index + 1 < _size);
		_matrices[_index++] = m;
	}

	mat4& pop(void) {
		assert(_index - 1 >= 0);
		_index--;
		return _matrices[_index];
	}
};


MatrixStack  mvstack;
mat4         model_view = mat4(1.0);
mat4         projmat = mat4(1.0);

/*                    NODE                  */
/*                    STUFF                   */

enum {
	sphere = 0,
	ellipse = 1,
	cylinder = 2,
	NumNodes,
	Quit
};



struct Node {
	mat4  transform;
	void(*render)(void);
	Node* sibling;
	Node* child;

	Node() :
		render(nullptr), sibling(nullptr), child(nullptr) {}

	Node(mat4& m, void(*render)(void), Node* sibling, Node* child) :
		transform(m), render(render), sibling(sibling), child(child) {}
};

Node  nodes[NumNodes];

void initNodes(void)
{
	mat4  m;

	m = Translate(-1.5, 3, -1.0)*Scale(0.75, 0.75, 0.75);
	nodes[sphere] = Node(m, paint_sphere, &nodes[ellipse], nullptr);

	m = Translate(-1, 1, -.5)*Scale(0.35, 1.0, 0.75);
	nodes[ellipse] = Node(m, paint_ellipse, &nodes[cylinder], nullptr);

	m = Translate(1, 2, .5)*Scale(0.75, 0.75, 0.75);
	nodes[cylinder] = Node(m, paint_cylinder, nullptr, nullptr);
}



void traverse(Node* node)
{
	if (node == nullptr) { return; }

	mvstack.push(model_view);

	model_view *= node->transform;
	node->render();

	if (node->child) { traverse(node->child); }

	model_view = mvstack.pop();

	if (node->sibling) { traverse(node->sibling); }
}