//hello there.....


#include "Angel.h"
#include "glm.h"
//#include "Source.h"
//#include "Header.h"
#include <assert.h>
#include <ctime>

#pragma once
#ifndef PI
#define PI  3.14159265358979323846
#endif
#define X               0
#define Y               1
#define Z               2
#define SCALE_VECTOR    1.0
#define SCALE_ANGLE     1.0


GLuint Gvao;

GLuint GProgram[10];

void m_glewInitAndVersion(void);
void reshape(int width, int height);

GLuint program[20];
GLuint VAO[30];
GLuint buffers[30];

enum { cube_vertices, cube_indeces, wire_indeces, cube_vertices_explicit };

typedef Angel::vec4  color4;
typedef Angel::vec4  point4;


void draw_road(void);

//Attributes 

const int  NumTriangles = 18; // (4 faces)(2 triangles/face)
const int  NumVertices = 3 * NumTriangles;


GLubyte* IMAGE4;
GLubyte* IMAGE5;
GLubyte* IMAGE6;

// Vertex data arrays

point4  POINTSS[NumVertices];
vec3    quad_Normal[NumVertices];
vec2    TEXT_CORRDS[NumVertices];

// Global Transformation matrices 
mat4 modelViewCamera;

//----------------------------------------------------------------------------

bool mouseDown = false;
float xrot = -20;
float yrot = 0;
float xdiff = 0;
float ydiff = 0;


// Setup some lights
vec4 light_ambient(0.5, 0.5, 0.0, 1.0);
vec4 light_diffuse(1.0, 1.0, 1.0, 1.0);
vec4 light_specular(1.0, 1.0, 1.0, 1.0);
//LIGHT POSITION
vec4 light_position = vec4(0.0, 1.0, 3.0, 1.0);

int Index = 0;

//----------------------------------------------------------------------------

/////Camera unv basis///////

Angel::vec4 eye = vec4(0.0, 1.5, 3.0, 1.0);
Angel::vec4 eye2 = vec4(0.0, 11.5, 3.0, 1.0);
Angel::vec4 v = vec4(0.0, 1.0, 0.0, 00);
Angel::vec4 u = vec4(1.0, 0.0, 0.0, 0.0);
Angel::vec4 n = Angel::normalize(vec4(0.0, 0.0, 1.0, 0.0));


GLfloat step = 20;
GLfloat theta_y = 0;
int spinToggle = 0;
GLfloat d = 0.5;
int w; int h;

const int NumTimesToSubdivide = 5;
const int num_tri = 4096;
const int num_vertexes = 3 * num_tri;
int tri_index = 0;
int cylinder_vertexes = 600;
int cylinder_vertexes2 = 600;
int TextureWidth[30];
int TextureHeight[30];
int moveObject = 0;
int curx, cury;
int pFlag = 1; //toggle object flag if picked

			   // RGBA olors
color4 blue_transparent = color4(0.098, 0.098, 0.439, .9);
color4 green_transparent = color4(0.098, 0.098, 0.439, .1);
color4 brown_transparent = color4(0.545, 0.271, 0.075, 1);
color4 red_transparent = color4(0.698, 0.133, 0.133, 1);
color4 black_transparent = color4(0.0, 0.0, 0.0, 1);
color4 slate_transparent = color4(0.416, 0.353, 0.804, .5);
color4 mount_transparent = color4(0.690, 0.878, 0.902, 1);

//uniform variables locations
GLuint color_loc;
GLuint proj_loc;
GLuint model_view_loc;

typedef Angel::vec4 point4;
typedef Angel::vec4 color4;



point4 points[num_vertexes];
vec3   normals[num_vertexes];
vec2   tex_coords[num_vertexes];

point4 scene_light_pos(4.0, 0.0, 1.0, 0.0);
float spin = 0.0, spin_step = 0.001;
float  material_shininess;

point4 cylinderData[600];

point4 cylinderData2[600];

GLuint  ModelView, Projection, NormalTransformation, ModelViewObj, vPosition, vNormal, vColor, vTexCoord;
GLuint textures[30];
GLuint texturesROAD[30];
GLuint sProgram[3];
GLuint sBuffers[9];
GLuint vao[30]; //


				// Vertices of a unit cube centered at origin, sides aligned with axes
point4 vertices[8] = {
	point4(-0.5, -0.5,  0.5, 1.0),
	point4(-0.5,  0.5,  0.5, 1.0),
	point4(0.5,  0.5,  0.5, 1.0),
	point4(0.5, -0.5,  0.5, 1.0),
	point4(-0.5, -0.5, -0.5, 1.0),
	point4(-0.5,  0.5, -0.5, 1.0),
	point4(0.5,  0.5, -0.5, 1.0),
	point4(0.5, -0.5, -0.5, 1.0)
};




point4 cube_vertices_positions[24] = {
	//x_positive
	point4(1.0f, -1.0f, -1.0f, 1.0f),
	point4(1.0f, -1.0f,  1.0f, 1.0f),
	point4(1.0f,  1.0f,  1.0f, 1.0f),
	point4(1.0f,  1.0f, -1.0f, 1.0f),
	//x-negative
	point4(-1.0f, -1.0f,  1.0f, 1.0f),
	point4(-1.0f, -1.0f, -1.0f, 1.0f),
	point4(-1.0f,  1.0f, -1.0f, 1.0f),
	point4(-1.0f,  1.0f,  1.0f, 1.0f),
	//y-positive
	point4(-1.0f,  1.0f, -1.0f, 1.0f),
	point4(1.0f,  1.0f, -1.0f, 1.0f),
	point4(1.0f,  1.0f,  1.0f, 1.0f),
	point4(-1.0f,  1.0f,  1.0f, 1.0f),
	//y-negatve
	point4(-1.0f, -1.0f,  1.0f, 1.0f),
	point4(1.0f, -1.0f,  1.0f, 1.0f),
	point4(1.0f, -1.0f, -1.0f, 1.0f),
	point4(-1.0f, -1.0f, -1.0f, 1.0f),
	//z-positive
	point4(1.0f, -1.0f,  1.0f, 1.0f),
	point4(-1.0f, -1.0f,  1.0f, 1.0f),
	point4(-1.0f,  1.0f,  1.0f, 1.0f),
	point4(1.0f,  1.0f,  1.0f, 1.0f),
	//z-negative
	point4(-1.0f, -1.0f, -1.0f, 1.0f),
	point4(1.0f, -1.0f, -1.0f, 1.0f),
	point4(1.0f,  1.0f, -1.0f, 1.0f),
	point4(-1.0f,  1.0f, -1.0f, 1.0f)
};

// A generate 12 flat shaded triangles using pointers to vertices (from 8 // vertices)

GLubyte indices[] = {
	1, 0, 3,
	1, 3, 2,
	2, 3, 7,
	2, 7, 6,
	3, 0, 4,
	3, 4, 7,
	6, 5, 1,
	6, 1, 2,
	4, 5, 6,
	4, 6, 7,
	5, 4, 0,
	5, 0, 1
};



//ground stuff
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

void
quad(int a, int b, int c, int d)
{
	point4 vertices[8] = {
		point4(-0.5, -0.5,  0.5, 1.0),
		point4(-0.5,  0.5,  0.5, 1.0),
		point4(0.5,  0.5,  0.5, 1.0),
		point4(0.5, -0.5,  0.5, 1.0),
		point4(-0.5, -0.5, -0.5, 1.0),
		point4(-0.5,  0.5, -0.5, 1.0),
		point4(0.5,  0.5, -0.5, 1.0),
		point4(0.5, -0.5, -0.5, 1.0)
	};


	POINTSS[Index] = vertices[a];
	quad_Normal[Index] = normalize(vec3(POINTSS[Index][0], 0.0, POINTSS[Index][2]));
	TEXT_CORRDS[Index] = vec2(0.0, 0.0);//1.0, 0.0
	Index++;

	POINTSS[Index] = vertices[b];
	quad_Normal[Index] = normalize(vec3(POINTSS[Index][0], 0.0, POINTSS[Index][2]));
	TEXT_CORRDS[Index] = vec2(0.0, 1.0);//1.0, 0.0
	Index++;

	POINTSS[Index] = vertices[c];
	quad_Normal[Index] = normalize(vec3(POINTSS[Index][0], 0.0, POINTSS[Index][2]));
	TEXT_CORRDS[Index] = vec2(1.0, 1.0);//1.0, 0.0
	Index++;


	POINTSS[Index] = vertices[a];
	quad_Normal[Index] = normalize(vec3(POINTSS[Index][0], 0.0, POINTSS[Index][2]));
	TEXT_CORRDS[Index] = vec2(0.0, 0.0);//1.0, 0.0
	Index++;


	POINTSS[Index] = vertices[c];
	quad_Normal[Index] = normalize(vec3(POINTSS[Index][0], 0.0, POINTSS[Index][2]));
	TEXT_CORRDS[Index] = vec2(1.0, 1.0);
	Index++;


	POINTSS[Index] = vertices[d];
	quad_Normal[Index] = normalize(vec3(POINTSS[Index][0], 0.0, POINTSS[Index][2]));
	TEXT_CORRDS[Index] = vec2(1.0, 0.0);//1.0, 0.0
	Index++;
}

//----------------------------------------------------------------------------

void
cyllMesh()
{
	quad(1, 0, 3, 2);
	quad(2, 3, 7, 6);
	quad(6, 2, 1, 5);//top
	quad(4, 5, 6, 7);
	quad(5, 4, 0, 1);
	quad(0, 4, 7, 3);//bottom
}

GLubyte* image0;
GLubyte* image1;
GLubyte* image2;
GLubyte* image3;

void make_sphere(void);
void paint_sphere(void);
void make_cylinder(void);
void paint_cylinder(void);
void paint_ellipse(void);
void make_ground(void);
void paint_ground(void);
void buildRoad(void);
void drawRoad(void);

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



//Skybox struc
GLuint texture;
typedef struct
{

	int topWidth;
	int topHeight;
	GLubyte *top;

	int bottomWidth;
	int bottomHeight;
	GLubyte *bottom;

	int leftHeight;
	int leftWidth;
	GLubyte *left;


	int rightWidth;
	int rightHeight;
	GLubyte *right;

	int frontWidth;
	int frontHeight;
	GLubyte *front;

	int backWidth;
	int backHeight;
	GLubyte *back;

} CubeMap;

CubeMap skybox;


//make sure you start with the default coordinate system


mat4 modelviewStackTop = mat4(1.0);
mat4 modelviewStackBottom = mat4(1.0);


//----------------------------------------------------------------------------


/*                    NODE                  */
/*                    STUFF                   */

enum {
	sphere = 0,
	ellipse = 1,
	cylinder = 2,
	ground = 3,
	road = 4,
	tree1 = 5,
	tree2 = 6,
	tree3 = 7,
	index_house = 8,
	thing,
	thing2,thing3,thing4,
	thing5,
	thing6,
	thing7,
	thing8,
	thing9,
	thing10,
	thing11,
	thing12,
	thing13,
	thing14,
	thing15,
	thing16,
	thing17,
	thing19,
	thing20, thing21, thing22, thing23, thing24, thing25, thing26, thing27, thing28, thing29, thing30,
	thing31, thing32, thing33, thing34, thing35, thing36, thing37, thing38, thing39, thing40,
	thing41, thing42, thing43, thing44, thing45, thing46, thing47, thing48, thing49, thing50,
	thing51, thing52, thing53, thing54, thing55, thing56, thing57, thing58, thing59, thing60,
	thing61, thing62, thing63, thing64, thing65, thing66, thing67, thing68, thing69, thing70,
	thing71, thing72, thing73, thing74, thing75, thing76, thing77, thing78, thing79, thing80,
	thing81, thing82, thing83, thing84, thing85, thing86, thing87, thing88, thing89, thing90,
	thing91, thing92, thing93, thing94, thing95, thing96, thing97, thing98, thing99, thing100,
	NumNodes,
	Quit,
};//cube_vertices, cube_indeces, wire_indeces, cube_vertices_explicit

point4 house_points[70];
color4 color_of_house[70];
int HouseVertices = 70;
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
int node_index = 0;

void initNodes(void)
{
	mat4  m;   
	float flip = 0;

	srand((unsigned int)time(nullptr));

	m = Translate(-2.5, 3, -2.0)*Scale(1.75, 1.75, 1.75);
	nodes[node_index] = Node(m, paint_sphere, &nodes[node_index+1], nullptr);
	node_index++;
	m = Translate(-2.5, 1, -2.0)*Scale(0.35, 2, 0.75);
	nodes[node_index] = Node(m, paint_ellipse, &nodes[node_index + 1], nullptr);
	node_index++;
	m = Translate(1, 2, .5)*Scale(0.75, 0.75, 0.75);//0.75, 0.75, 0.75
	nodes[node_index] = Node(m, paint_cylinder, &nodes[node_index + 1], nullptr);
	node_index++;
	m = Translate(0, 0, .7)*Scale(800, 0.1, 800);//0.75, 0.75, 0.75   basically cylinder 2
	nodes[node_index] = Node(m, paint_ground, &nodes[node_index + 1], nullptr);
	node_index++;
	m = Translate(1, 2, .5)*Scale(10, 10, 10);//0.75, 0.75, 0.75

	nodes[node_index] = Node(m, drawRoad, &nodes[node_index + 1], nullptr);
	node_index++;

	m = Translate(-2.5, 3, -8.0)*Scale(1.75, 1.75, 1.75);
	nodes[node_index] = Node(m, paint_sphere, &nodes[node_index + 1], nullptr);
	node_index++;

	m = Translate(-2.5, 3, -14.0)*Scale(1.75, 1.75, 1.75);
	nodes[node_index] = Node(m, paint_sphere, &nodes[node_index + 1], nullptr);
	node_index++;
	m = Translate(-2.5, 1, -14.0)*Scale(0.35, 2, 0.75);
	nodes[node_index] = Node(m, paint_ellipse, &nodes[node_index + 1], nullptr);
	node_index++;

	m = Translate(-2.5, 3, -20.0)*Scale(1.75, 1.75, 1.75);
	nodes[node_index] = Node(m, paint_sphere, &nodes[node_index + 1], nullptr);
	node_index++;
	m = Translate(-2.5, 1, -20.0)*Scale(0.35, 2, 0.75);
	nodes[node_index] = Node(m, paint_ellipse, &nodes[node_index + 1], nullptr);
	node_index++;

	m = Translate(-2.5, 3, -26.0)*Scale(1.75, 1.75, 1.75);
	nodes[node_index] = Node(m, paint_sphere, &nodes[node_index + 1], nullptr);
	node_index++;
	m = Translate(-2.5, 1, -26.0)*Scale(0.35, 2, 0.75);
	nodes[node_index] = Node(m, paint_ellipse, &nodes[node_index + 1], nullptr);
	node_index++;

	m = Translate(-2.5, 3, -32.0)*Scale(1.75, 1.75, 1.75);
	nodes[node_index] = Node(m, paint_sphere, &nodes[node_index + 1], nullptr);
	node_index++;
	m = Translate(-2.5, 1, -32.0)*Scale(0.35, 2, 0.75);
	nodes[node_index] = Node(m, paint_ellipse, &nodes[node_index + 1], nullptr);
	node_index++;


	m = Translate(-2.5, 3, -38.0)*Scale(1.75, 1.75, 1.75);
	nodes[node_index] = Node(m, paint_sphere, &nodes[node_index + 1], nullptr);
	node_index++;
	m = Translate(-2.5, 1, -38.0)*Scale(0.35, 2, 0.75);
	nodes[node_index] = Node(m, paint_ellipse, &nodes[node_index + 1], nullptr);
	node_index++;


	m = Translate(-2.5, 3, -42.0)*Scale(1.75, 1.75, 1.75);
	nodes[node_index] = Node(m, paint_sphere, &nodes[node_index + 1], nullptr);
	node_index++;
	m = Translate(-2.5, 1, -42.0)*Scale(0.35, 2, 0.75);
	nodes[node_index] = Node(m, paint_ellipse, &nodes[node_index + 1], nullptr);
	node_index++;


	m = Translate(-2.5, 3, -48.0)*Scale(1.75, 1.75, 1.75);
	nodes[node_index] = Node(m, paint_sphere, &nodes[node_index + 1], nullptr);
	node_index++;
	m = Translate(-2.5, 1, -48.0)*Scale(0.35, 2, 0.75);
	nodes[node_index] = Node(m, paint_ellipse, &nodes[node_index + 1], nullptr);
	node_index++;

	m = Translate(-2.5, 3, -52.0)*Scale(1.75, 1.75, 1.75);
	nodes[node_index] = Node(m, paint_sphere, &nodes[node_index + 1], nullptr);
	node_index++;
	m = Translate(-2.5, 1, -52.0)*Scale(0.35, 2, 0.75);
	nodes[node_index] = Node(m, paint_ellipse, &nodes[node_index + 1], nullptr);
	node_index++;

	m = Translate(-2.5, 3, -58.0)*Scale(1.75, 1.75, 1.75);
	nodes[node_index] = Node(m, paint_sphere, &nodes[node_index + 1], nullptr);
	node_index++;
	m = Translate(-2.5, 1, -58.0)*Scale(0.35, 2, 0.75);
	nodes[node_index] = Node(m, paint_ellipse, &nodes[node_index + 1], nullptr);
	node_index++;


	m = Translate(-2.5, 3, -62.0)*Scale(1.75, 1.75, 1.75);
	nodes[node_index] = Node(m, paint_sphere, &nodes[node_index + 1], nullptr);
	node_index++;
	m = Translate(-2.5, 1, -62.0)*Scale(0.35, 2, 0.75);
	nodes[node_index] = Node(m, paint_ellipse, &nodes[node_index + 1], nullptr);
	node_index++;

	m = Translate(-2.5, 3, -68.0)*Scale(1.75, 1.75, 1.75);
	nodes[node_index] = Node(m, paint_sphere, &nodes[node_index + 1], nullptr);
	node_index++;
	m = Translate(-2.5, 1, -68.0)*Scale(0.35, 2, 0.75);
	nodes[node_index] = Node(m, paint_ellipse, &nodes[node_index + 1], nullptr);
	node_index++;

	m = Translate(-2.5, 3, -72.0)*Scale(1.75, 1.75, 1.75);
	nodes[node_index] = Node(m, paint_sphere, &nodes[node_index + 1], nullptr);
	node_index++;
	m = Translate(-2.5, 1, -72.0)*Scale(0.35, 2, 0.75);
	nodes[node_index] = Node(m, paint_ellipse, &nodes[node_index + 1], nullptr);
	node_index++;


	m = Translate(-2.5, 3, -78.0)*Scale(1.75, 1.75, 1.75);
	nodes[node_index] = Node(m, paint_sphere, &nodes[node_index + 1], nullptr);
	node_index++;
	m = Translate(-2.5, 1, -78.0)*Scale(0.35, 2, 0.75);
	nodes[node_index] = Node(m, paint_ellipse, &nodes[node_index + 1], nullptr);
	node_index++;

	m = Translate(-2.5, 3, -82.0)*Scale(1.75, 1.75, 1.75);
	nodes[node_index] = Node(m, paint_sphere, &nodes[node_index + 1], nullptr);
	node_index++;
	m = Translate(-2.5, 1, -82.0)*Scale(0.35, 2, 0.75);
	nodes[node_index] = Node(m, paint_ellipse, &nodes[node_index + 1], nullptr);
	node_index++;

	m = Translate(-2.5, 3, -88.0)*Scale(1.75, 1.75, 1.75);
	nodes[node_index] = Node(m, paint_sphere, &nodes[node_index + 1], nullptr);
	node_index++;
	m = Translate(-2.5, 1, -88.0)*Scale(0.35, 2, 0.75);
	nodes[node_index] = Node(m, paint_ellipse, &nodes[node_index + 1], nullptr);
	node_index++;

	m = Translate(-2.5, 3, -92.0)*Scale(1.75, 1.75, 1.75);
	nodes[node_index] = Node(m, paint_sphere, &nodes[node_index + 1], nullptr);
	node_index++;
	m = Translate(-2.5, 1, -92.0)*Scale(0.35, 2, 0.75);
	nodes[node_index] = Node(m, paint_ellipse, &nodes[node_index + 1], nullptr);
	node_index++;


	m = Translate(-2.5, 3, -102.0)*Scale(1.75, 1.75, 1.75);
	nodes[node_index] = Node(m, paint_sphere, &nodes[node_index + 1], nullptr);
	node_index++;
	m = Translate(-2.5, 1, -102.0)*Scale(0.35, 2, 0.75);
	nodes[node_index] = Node(m, paint_ellipse, &nodes[node_index + 1], nullptr);
	node_index++;


	m = Translate(5, 3, -14.0)*Scale(1.75, 1.75, 1.75);
	nodes[node_index] = Node(m, paint_sphere, &nodes[node_index + 1], nullptr);
	node_index++;
	m = Translate(5, 1, -14.0)*Scale(0.35, 2, 0.75);
	nodes[node_index] = Node(m, paint_ellipse, &nodes[node_index + 1], nullptr);
	node_index++;

	m = Translate(5, 3, -20.0)*Scale(1.75, 1.75, 1.75);
	nodes[node_index] = Node(m, paint_sphere, &nodes[node_index + 1], nullptr);
	node_index++;
	m = Translate(5, 1, -20.0)*Scale(0.35, 2, 0.75);
	nodes[node_index] = Node(m, paint_ellipse, &nodes[node_index + 1], nullptr);
	node_index++;

	m = Translate(5, 3, -26.0)*Scale(1.75, 1.75, 1.75);
	nodes[node_index] = Node(m, paint_sphere, &nodes[node_index + 1], nullptr);
	node_index++;
	m = Translate(5, 1, -26.0)*Scale(0.35, 2, 0.75);
	nodes[node_index] = Node(m, paint_ellipse, &nodes[node_index + 1], nullptr);
	node_index++;

	m = Translate(5, 3, -32.0)*Scale(1.75, 1.75, 1.75);
	nodes[node_index] = Node(m, paint_sphere, &nodes[node_index + 1], nullptr);
	node_index++;
	m = Translate(5, 1, -32.0)*Scale(0.35, 2, 0.75);
	nodes[node_index] = Node(m, paint_ellipse, &nodes[node_index + 1], nullptr);
	node_index++;


	m = Translate(5, 3, -38.0)*Scale(1.75, 1.75, 1.75);
	nodes[node_index] = Node(m, paint_sphere, &nodes[node_index + 1], nullptr);
	node_index++;
	m = Translate(5, 1, -38.0)*Scale(0.35, 2, 0.75);
	nodes[node_index] = Node(m, paint_ellipse, &nodes[node_index + 1], nullptr);
	node_index++;


	m = Translate(5, 3, -42.0)*Scale(1.75, 1.75, 1.75);
	nodes[node_index] = Node(m, paint_sphere, &nodes[node_index + 1], nullptr);
	node_index++;
	m = Translate(5, 1, -42.0)*Scale(0.35, 2, 0.75);
	nodes[node_index] = Node(m, paint_ellipse, &nodes[node_index + 1], nullptr);
	node_index++;


	m = Translate(5, 3, -48.0)*Scale(1.75, 1.75, 1.75);
	nodes[node_index] = Node(m, paint_sphere, &nodes[node_index + 1], nullptr);
	node_index++;
	m = Translate(5, 1, -48.0)*Scale(0.35, 2, 0.75);
	nodes[node_index] = Node(m, paint_ellipse, &nodes[node_index + 1], nullptr);
	node_index++;

	m = Translate(5, 3, -52.0)*Scale(1.75, 1.75, 1.75);
	nodes[node_index] = Node(m, paint_sphere, &nodes[node_index + 1], nullptr);
	node_index++;
	m = Translate(5, 1, -52.0)*Scale(0.35, 2, 0.75);
	nodes[node_index] = Node(m, paint_ellipse, &nodes[node_index + 1], nullptr);
	node_index++;

	m = Translate(5, 3, -58.0)*Scale(1.75, 1.75, 1.75);
	nodes[node_index] = Node(m, paint_sphere, &nodes[node_index + 1], nullptr);
	node_index++;
	m = Translate(5, 1, -58.0)*Scale(0.35, 2, 0.75);
	nodes[node_index] = Node(m, paint_ellipse, &nodes[node_index + 1], nullptr);
	node_index++;


	m = Translate(5, 3, -62.0)*Scale(1.75, 1.75, 1.75);
	nodes[node_index] = Node(m, paint_sphere, &nodes[node_index + 1], nullptr);
	node_index++;
	m = Translate(5, 1, -62.0)*Scale(0.35, 2, 0.75);
	nodes[node_index] = Node(m, paint_ellipse, &nodes[node_index + 1], nullptr);
	node_index++;

	m = Translate(5, 3, -68.0)*Scale(1.75, 1.75, 1.75);
	nodes[node_index] = Node(m, paint_sphere, &nodes[node_index + 1], nullptr);
	node_index++;
	m = Translate(5, 1, -68.0)*Scale(0.35, 2, 0.75);
	nodes[node_index] = Node(m, paint_ellipse, &nodes[node_index + 1], nullptr);
	node_index++;

	m = Translate(5, 3, -72.0)*Scale(1.75, 1.75, 1.75);
	nodes[node_index] = Node(m, paint_sphere, &nodes[node_index + 1], nullptr);
	node_index++;
	m = Translate(5, 1, -72.0)*Scale(0.35, 2, 0.75);
	nodes[node_index] = Node(m, paint_ellipse, &nodes[node_index + 1], nullptr);
	node_index++;


	m = Translate(5, 3, -78.0)*Scale(1.75, 1.75, 1.75);
	nodes[node_index] = Node(m, paint_sphere, &nodes[node_index + 1], nullptr);
	node_index++;
	m = Translate(5, 1, -78.0)*Scale(0.35, 2, 0.75);
	nodes[node_index] = Node(m, paint_ellipse, &nodes[node_index + 1], nullptr);
	node_index++;

	m = Translate(5, 3, -82.0)*Scale(1.75, 1.75, 1.75);
	nodes[node_index] = Node(m, paint_sphere, &nodes[node_index + 1], nullptr);
	node_index++;
	m = Translate(5, 1, -82.0)*Scale(0.35, 2, 0.75);
	nodes[node_index] = Node(m, paint_ellipse, &nodes[node_index + 1], nullptr);
	node_index++;

	m = Translate(5, 3, -88.0)*Scale(1.75, 1.75, 1.75);
	nodes[node_index] = Node(m, paint_sphere, &nodes[node_index + 1], nullptr);
	node_index++;
	m = Translate(5, 1, -88.0)*Scale(0.35, 2, 0.75);
	nodes[node_index] = Node(m, paint_ellipse, &nodes[node_index + 1], nullptr);
	node_index++;

	m = Translate(5, 3, -92.0)*Scale(1.75, 1.75, 1.75);
	nodes[node_index] = Node(m, paint_sphere, &nodes[node_index + 1], nullptr);
	node_index++;
	m = Translate(5, 1, -92.0)*Scale(0.35, 2, 0.75);
	nodes[node_index] = Node(m, paint_ellipse, &nodes[node_index + 1], nullptr);
	node_index++;


	m = Translate(5, 3, -102.0)*Scale(1.75, 1.75, 1.75);
	nodes[node_index] = Node(m, paint_sphere, &nodes[node_index + 1], nullptr);
	node_index++;
	m = Translate(5, 1, -102.0)*Scale(0.35, 2, 0.75);
	nodes[node_index] = Node(m, paint_ellipse, &nodes[node_index + 1], nullptr);
	node_index++;


	m = Translate(5, 3, -8.0)*Scale(1.75, 1.75, 1.75);
	nodes[node_index] = Node(m, paint_sphere, &nodes[node_index + 1], nullptr);
	node_index++;
	m = Translate(5, 1, -8.0)*Scale(0.35, 2, 0.75);
	nodes[node_index] = Node(m, paint_ellipse, &nodes[node_index + 1], nullptr);
	node_index++;

	m = Translate(5, 3, -2.0)*Scale(1.75, 1.75, 1.75);
	nodes[node_index] = Node(m, paint_sphere, &nodes[node_index + 1], nullptr);
	node_index++;
	m = Translate(5, 1, -2.0)*Scale(0.35, 2, 0.75);
	nodes[node_index] = Node(m, paint_ellipse, &nodes[node_index + 1], nullptr);
	node_index++;

	m = Translate(7, 30, -188.0)*Scale(20.75, 20.75, 20.75);
	nodes[node_index] = Node(m, paint_sphere, &nodes[node_index + 1], nullptr);
	node_index++;
	m = Translate(-4, 30, -188.0)*Scale(20.75, 20.75, 20.75);
	nodes[node_index] = Node(m, paint_sphere, &nodes[node_index + 1], nullptr);
	node_index++;

	m = Translate(1, 50, -188.0)*Scale(20.75, 20.75, 20.75);
	nodes[node_index] = Node(m, paint_sphere, &nodes[node_index + 1], nullptr);
	node_index++;

	m = Translate(2, 1, -188.0)*Scale(10.35, 30, 10.75);
	nodes[node_index] = Node(m, paint_ellipse, &nodes[node_index + 1], nullptr);
	node_index++;

	m = Translate(-2.5, 1, -8.0)*Scale(0.35, 2, 0.75);
	nodes[node_index] = Node(m, paint_ellipse, nullptr, nullptr);
	
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





/*                    SPHERE                  */
/*                    MAKE                    */

void make_sphere()
{
	tetrahedron(NumTimesToSubdivide);
}

/*                    CYLINDER                  */
/*                    MAKE                      */
void make_cylinder()
{
	{
		GLfloat x, z, theta;
		int iMax = 50, vertexnumberer = 0;

		for (int i = 0; i < iMax; i++) {
			theta = (2 * PI / (float)iMax)*i; x = cos(theta); z = sin(theta);
			cylinderData[vertexnumberer] = vec4(0, 0, 0, 1.0);
			tex_coords[vertexnumberer] = vec2(cylinderData[vertexnumberer][0], cylinderData[vertexnumberer][2]);
			vertexnumberer++;
			cylinderData[vertexnumberer] = vec4(x, 0, z, 1.0);
			tex_coords[vertexnumberer] = vec2(cylinderData[vertexnumberer][0], cylinderData[vertexnumberer][2]);
			vertexnumberer++;
			theta = (2 * PI / (float)iMax)*(i + 1.0); x = cos(theta); z = sin(theta);
			cylinderData[vertexnumberer] = vec4(x, 0, z, 1.0);
			tex_coords[vertexnumberer] = vec2(cylinderData[vertexnumberer][0], cylinderData[vertexnumberer][2]);
			vertexnumberer++;
		}

		for (int i = 0; i < iMax; i++) {
			theta = (2 * PI / (float)iMax)*i; x = cos(theta); z = sin(theta);
			cylinderData[vertexnumberer] = vec4(x, 1, z, 1.0);
			tex_coords[vertexnumberer] = vec2(cylinderData[vertexnumberer][0], cylinderData[vertexnumberer][1]);
			vertexnumberer++;
			cylinderData[vertexnumberer] = vec4(x, 0, z, 1.0);
			tex_coords[vertexnumberer] = vec2(cylinderData[vertexnumberer][0], cylinderData[vertexnumberer][1]);
			vertexnumberer++;

			theta = (2 * PI / (float)iMax)*(i + 1.0); x = cos(theta); z = sin(theta);
			cylinderData[vertexnumberer] = vec4(x, 1, z, 1.0);
			tex_coords[vertexnumberer] = vec2(cylinderData[vertexnumberer][0], cylinderData[vertexnumberer][1]);
			vertexnumberer++;
			cylinderData[vertexnumberer] = vec4(x, 1, z, 1.0);
			tex_coords[vertexnumberer] = vec2(cylinderData[vertexnumberer][0], cylinderData[vertexnumberer][1]);
			vertexnumberer++;

			theta = (2 * PI / (float)iMax)*i; x = cos(theta); z = sin(theta);
			cylinderData[vertexnumberer] = vec4(x, 0, z, 1.0);
			tex_coords[vertexnumberer] = vec2(cylinderData[vertexnumberer][0], cylinderData[vertexnumberer][1]);
			vertexnumberer++;

			theta = (2 * PI / (float)iMax)*(i + 1.0); x = cos(theta); z = sin(theta);
			cylinderData[vertexnumberer] = vec4(x, 0, z, 1.0);
			tex_coords[vertexnumberer] = vec2(cylinderData[vertexnumberer][0], cylinderData[vertexnumberer][1]);
			vertexnumberer++;

		}

		for (int i = 0; i < iMax; i++) {
			theta = (2 * PI / (float)iMax)*i; x = cos(theta); z = sin(theta);
			cylinderData[vertexnumberer] = vec4(0, 1, 0, 1.0);
			tex_coords[vertexnumberer] = vec2(0, 0);
			vertexnumberer++;
			cylinderData[vertexnumberer] = vec4(x, 1, z, 1.0);
			tex_coords[vertexnumberer] = vec2(cylinderData[vertexnumberer][0], cylinderData[vertexnumberer][2]);
			vertexnumberer++;

			theta = (2 * PI / (float)iMax)*(i + 1.0); x = cos(theta); z = sin(theta);
			cylinderData[vertexnumberer] = vec4(x, 1, z, 1.0);
			tex_coords[vertexnumberer] = vec2(cylinderData[vertexnumberer][0], cylinderData[vertexnumberer][2]);
			vertexnumberer++;
		}
	}
}


void make_ground()
{
	{
		GLfloat x, z, theta;
		int iMax = 50, vertexnumberer = 0;

		for (int i = 0; i < iMax; i++) {
			theta = (2 * PI / (float)iMax)*i; x = cos(theta); z = sin(theta);
			cylinderData2[vertexnumberer] = vec4(0, 0, 0, 1.0);
			tex_coords[vertexnumberer] = vec2(cylinderData2[vertexnumberer][0], cylinderData2[vertexnumberer][2]);
			vertexnumberer++;
			cylinderData2[vertexnumberer] = vec4(x, 0, z, 1.0);
			tex_coords[vertexnumberer] = vec2(cylinderData2[vertexnumberer][0], cylinderData2[vertexnumberer][2]);
			vertexnumberer++;
			theta = (2 * PI / (float)iMax)*(i + 1.0); x = cos(theta); z = sin(theta);
			cylinderData2[vertexnumberer] = vec4(x, 0, z, 1.0);
			tex_coords[vertexnumberer] = vec2(cylinderData2[vertexnumberer][0], cylinderData2[vertexnumberer][2]);
			vertexnumberer++;
		}

		for (int i = 0; i < iMax; i++) {
			theta = (2 * PI / (float)iMax)*i; x = cos(theta); z = sin(theta);
			cylinderData2[vertexnumberer] = vec4(x, 1, z, 1.0);
			tex_coords[vertexnumberer] = vec2(cylinderData2[vertexnumberer][0], cylinderData2[vertexnumberer][1]);
			vertexnumberer++;
			cylinderData2[vertexnumberer] = vec4(x, 0, z, 1.0);
			tex_coords[vertexnumberer] = vec2(cylinderData2[vertexnumberer][0], cylinderData2[vertexnumberer][1]);
			vertexnumberer++;

			theta = (2 * PI / (float)iMax)*(i + 1.0); x = cos(theta); z = sin(theta);
			cylinderData2[vertexnumberer] = vec4(x, 1, z, 1.0);
			tex_coords[vertexnumberer] = vec2(cylinderData2[vertexnumberer][0], cylinderData2[vertexnumberer][1]);
			vertexnumberer++;
			cylinderData2[vertexnumberer] = vec4(x, 1, z, 1.0);
			tex_coords[vertexnumberer] = vec2(cylinderData2[vertexnumberer][0], cylinderData2[vertexnumberer][1]);
			vertexnumberer++;

			theta = (2 * PI / (float)iMax)*i; x = cos(theta); z = sin(theta);
			cylinderData2[vertexnumberer] = vec4(x, 0, z, 1.0);
			tex_coords[vertexnumberer] = vec2(cylinderData2[vertexnumberer][0], cylinderData2[vertexnumberer][1]);
			vertexnumberer++;

			theta = (2 * PI / (float)iMax)*(i + 1.0); x = cos(theta); z = sin(theta);
			cylinderData2[vertexnumberer] = vec4(x, 0, z, 1.0);
			tex_coords[vertexnumberer] = vec2(cylinderData2[vertexnumberer][0], cylinderData2[vertexnumberer][1]);
			vertexnumberer++;

		}

		for (int i = 0; i < iMax; i++) {
			theta = (2 * PI / (float)iMax)*i; x = cos(theta); z = sin(theta);
			cylinderData2[vertexnumberer] = vec4(0, 1, 0, 1.0);
			tex_coords[vertexnumberer] = vec2(0, 0);
			vertexnumberer++;
			cylinderData2[vertexnumberer] = vec4(x, 1, z, 1.0);
			tex_coords[vertexnumberer] = vec2(cylinderData2[vertexnumberer][0], cylinderData2[vertexnumberer][2]);
			vertexnumberer++;

			theta = (2 * PI / (float)iMax)*(i + 1.0); x = cos(theta); z = sin(theta);
			cylinderData2[vertexnumberer] = vec4(x, 1, z, 1.0);
			tex_coords[vertexnumberer] = vec2(cylinderData2[vertexnumberer][0], cylinderData2[vertexnumberer][2]);
			vertexnumberer++;
		}
	}
}

int	   roadVertices;
point4 roadData[50];
//color4 roadColor[50];
vec2   roadTexCoords[50];
vec3   roadNormals[50];

void buildRoad() {
	roadData[roadVertices] = vec4(-4.0, -2.9, 800.0, 1.0); roadNormals[roadVertices] = vec3(0, 1, 0); roadTexCoords[roadVertices] = vec2(1.0, 0.0); roadVertices++;
	roadData[roadVertices] = vec4(-4.0, -2.9, -800.0, 1.0); roadNormals[roadVertices] = vec3(0, 1, 0); roadTexCoords[roadVertices] = vec2(1.0, 10.0); roadVertices++;
	roadData[roadVertices] = vec4(4.0, -2.9, -800.0, 1.0); roadNormals[roadVertices] = vec3(0, 1, 0); roadTexCoords[roadVertices] = vec2(0.0, 10.0); roadVertices++;
	roadData[roadVertices] = vec4(4.0, -2.9, -800.0, 1.0); roadNormals[roadVertices] = vec3(0, 1, 0); roadTexCoords[roadVertices] = vec2(0.0, 10.0); roadVertices++;
	roadData[roadVertices] = vec4(4.0, -2.9, 800.0, 1.0); roadNormals[roadVertices] = vec3(0, 1, 0); roadTexCoords[roadVertices] = vec2(0.0, 0.0); roadVertices++;
	roadData[roadVertices] = vec4(-4.0, -2.9, 800.0, 1.0); roadNormals[roadVertices] = vec3(0, 1, 0); roadTexCoords[roadVertices] = vec2(1.0, 0.0); roadVertices++;
}


/*                    FUNCTIONS FOR                  */
/*                    PAINT                          */


vec4 material_ambient(0.8, 0.36, 0.36, 1.0);
vec4 material_diffuse(0.88, 0.34, 0.2, 1.0);
vec4 material_specular(1.0, 0.84, 0.77, 1.0);

GLuint  ModelViewCam; //Viewing portion of the ModelviewMatrix  uniform location
vec4 ambient_product = productComponentwise(light_ambient, material_ambient);
vec4 diffuse_product = productComponentwise(light_diffuse, material_diffuse);
vec4 specular_product = productComponentwise(light_specular, material_specular);
GLfloat theta = 0;

void draw_road(void)
{

	glUseProgram(GProgram[road]);

	// Bind the Ka/Kd/Ks to the shader
	glUniform4fv(glGetUniformLocation(GProgram[road], "AmbientProduct"), 1, ambient_product);
	glUniform4fv(glGetUniformLocation(GProgram[road], "DiffuseProduct"), 1, diffuse_product);
	glUniform4fv(glGetUniformLocation(GProgram[road], "SpecularProduct"), 1, specular_product);
	glUniform1f(glGetUniformLocation(GProgram[road], "mat_shininess"), material_shininess);
	glUniform4fv(glGetUniformLocation(GProgram[road], "lightPosition"), 1, light_position);
	// Retrieve transformation uniform variable locations
	ModelViewCam = glGetUniformLocation(GProgram[road], "modelView");
	ModelViewObj = glGetUniformLocation(GProgram[road], "ModelViewObj");
	Projection = glGetUniformLocation(GProgram[road], "projection");
	NormalTransformation = glGetUniformLocation(GProgram[road], "normalTransformation");

	mat4 modelViewCamera = LookAt(eye, eye - n, v);
	glUniformMatrix4fv(ModelViewCam, 1, GL_TRUE, modelViewCamera);

	mat4 modelViewObject = Scale(1.0, 2.2, 1.0);//RotateX(-theta/200.0)*
	mat4 normalMatrix = Scale(1.0, 1.0 / 2.2, 1.0);
	glUniformMatrix4fv(ModelViewObj, 1, GL_TRUE, modelViewObject);
	glUniformMatrix4fv(NormalTransformation, 1, GL_TRUE, normalMatrix);

	glBindVertexArray(Gvao);
	glDrawArrays(GL_TRIANGLES, 0, NumVertices);


	glUseProgram(0);
	glBindVertexArray(0);

}

vec4 light_position2 = (1.0, 1.0, -1.0, 0.0);
mat4 proj = mat4(1.0);
void drawRoad() {

	glUseProgram(program[road]);

	// Initialize shader lighting parameters
	color4 light_ambient(1, 1, 1, 1.0);
	color4 light_diffuse(1.0, 1.0, 1.0, 1.0);
	color4 light_specular(1.0, 1.0, 1.0, 1.0);

	color4 material_ambient(1, 1, 1, 1.0);
	color4 material_diffuse(1, 1, 1, 1.0);
	color4 material_specular(1, 1, 1, 1.0);
	float  material_shininess = 70.0;

	color4 ambient_product = productComponentwise(light_ambient, material_ambient);
	color4 diffuse_product = productComponentwise(light_diffuse, material_diffuse);
	color4 specular_product = productComponentwise(light_specular, material_specular);

	glUniform4fv(glGetUniformLocation(program[road], "AmbientProduct"),
		1, ambient_product);
	glUniform4fv(glGetUniformLocation(program[road], "DiffuseProduct"),
		1, diffuse_product);
	glUniform4fv(glGetUniformLocation(program[road], "SpecularProduct"),
		1, specular_product);
	glUniform4fv(glGetUniformLocation(program[road], "LightPosition"),
		1, light_position2);
	glUniform1f(glGetUniformLocation(program[road], "Shininess"),
		material_shininess);

	proj_loc = glGetUniformLocation(program[road], "Projection");
	model_view_loc = glGetUniformLocation(program[road], "ModelView");
	glUniformMatrix4fv(proj_loc, 1, GL_TRUE, proj);
	glUniformMatrix4fv(model_view_loc, 1, GL_TRUE, model_view);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texturesROAD[4]);

	glBindVertexArray(vao[3]);//1
	glDrawArrays(GL_TRIANGLES, 0, roadVertices);

	glBindVertexArray(0);

}


/*                    GROUND                  */
/*                    PAINT                    */
void paint_ground()
{

	glUseProgram(program[cylinder]);

	color4 light_ambient(0.2, 0.2, 0.2, 1.0);
	color4 light_diffuse(1.0, 1.0, 1.0, 1.0);
	color4 light_specular(1.0, 1.0, 1.0, 1.0);

	color4 material_ambient(0.19225, 0.19225, 0.19225, 1.0);
	color4 material_diffuse(0.50754, 0.50754, 0.50754, 1.0);
	color4 material_specular(0.508273, 0.508273, 0.508273, 1.0);
	float  material_shininess = 51.2;

	color4 ambient_product = productComponentwise(light_ambient, material_ambient);
	color4 diffuse_product = productComponentwise(light_diffuse, material_diffuse);
	color4 specular_product = productComponentwise(light_specular, material_specular);

	point4 spin_to_win = vec4(-3 * sin(spin), 12, -3 * cos(spin), 1.0);

	glUniform4fv(glGetUniformLocation(program[ground], "AmbientProduct"),
		1, ambient_product);
	glUniform4fv(glGetUniformLocation(program[ground], "DiffuseProduct"),
		1, diffuse_product);
	glUniform4fv(glGetUniformLocation(program[ground], "SpecularProduct"),
		1, specular_product);


	glUniform4fv(glGetUniformLocation(program[sphere], "LightPosition"),
		1, spin_to_win);

	glUniform4fv(glGetUniformLocation(program[sphere], "LightPosition2"),
		1, eye - vec4(1.0, 1.0, 0, 0));

	glUniform4fv(glGetUniformLocation(program[sphere], "LightPosition3"),
		1, scene_light_pos);

	glUniform4fv(glGetUniformLocation(program[ground], "AmbientProduct2"),
		1, ambient_product);
	glUniform4fv(glGetUniformLocation(program[ground], "DiffuseProduct2"),
		1, diffuse_product);
	glUniform4fv(glGetUniformLocation(program[ground], "SpecularProduct2"),
		1, specular_product);


	glUniform4fv(glGetUniformLocation(program[ground], "AmbientProduct3"),
		1, ambient_product);
	glUniform4fv(glGetUniformLocation(program[ground], "DiffuseProduct3"),
		1, diffuse_product);
	glUniform4fv(glGetUniformLocation(program[ground], "SpecularProduct3"),
		1, specular_product);

	glUniform1f(glGetUniformLocation(program[ground], "Shininess"),
		material_shininess);

	Projection = glGetUniformLocation(program[ground], "Projection");
	ModelView = glGetUniformLocation(program[ground], "ModelView");
	glUniformMatrix4fv(Projection, 1, GL_TRUE, projmat);
	glUniformMatrix4fv(ModelView, 1, GL_TRUE, model_view);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textures[3]);//

	glBindVertexArray(vao[1]);
	glDrawArrays(GL_TRIANGLES, 0, cylinder_vertexes2);//cylinder_vertexes
}




/*                    Cylinder                 */
/*                    PAINT                    */
void paint_cylinder()
{

	glUseProgram(program[cylinder]);

	color4 light_ambient(0.2, 0.2, 0.2, 1.0);
	color4 light_diffuse(1.0, 1.0, 1.0, 1.0);
	color4 light_specular(1.0, 1.0, 1.0, 1.0);

	color4 material_ambient(0.19225, 0.19225, 0.19225, 1.0);
	color4 material_diffuse(0.50754, 0.50754, 0.50754, 1.0);
	color4 material_specular(0.508273, 0.508273, 0.508273, 1.0);
	float  material_shininess = 70.2;

	color4 ambient_product = productComponentwise(light_ambient, material_ambient);
	color4 diffuse_product = productComponentwise(light_diffuse, material_diffuse);
	color4 specular_product = productComponentwise(light_specular, material_specular);

	point4 spin_to_win = vec4(-3 * sin(spin), 12, -3 * cos(spin), 1.0);

	glUniform4fv(glGetUniformLocation(program[cylinder], "AmbientProduct"),
		1, ambient_product);
	glUniform4fv(glGetUniformLocation(program[cylinder], "DiffuseProduct"),
		1, diffuse_product);
	glUniform4fv(glGetUniformLocation(program[cylinder], "SpecularProduct"),
		1, specular_product);


	glUniform4fv(glGetUniformLocation(program[sphere], "LightPosition"),
		1, spin_to_win);

	glUniform4fv(glGetUniformLocation(program[sphere], "LightPosition2"),
		1, eye - vec4(1.0, 1.0, 0, 0));

	glUniform4fv(glGetUniformLocation(program[sphere], "LightPosition3"),
		1, scene_light_pos);

	glUniform4fv(glGetUniformLocation(program[cylinder], "AmbientProduct2"),
		1, ambient_product);
	glUniform4fv(glGetUniformLocation(program[cylinder], "DiffuseProduct2"),
		1, diffuse_product);
	glUniform4fv(glGetUniformLocation(program[cylinder], "SpecularProduct2"),
		1, specular_product);


	glUniform4fv(glGetUniformLocation(program[cylinder], "AmbientProduct3"),
		1, ambient_product);
	glUniform4fv(glGetUniformLocation(program[cylinder], "DiffuseProduct3"),
		1, diffuse_product);
	glUniform4fv(glGetUniformLocation(program[cylinder], "SpecularProduct3"),
		1, specular_product);

	glUniform1f(glGetUniformLocation(program[cylinder], "Shininess"),
		material_shininess);


	Projection = glGetUniformLocation(program[cylinder], "Projection");
	ModelView = glGetUniformLocation(program[cylinder], "ModelView");
	glUniformMatrix4fv(Projection, 1, GL_TRUE, projmat);
	glUniformMatrix4fv(ModelView, 1, GL_TRUE, model_view);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textures[1]);//

	glBindVertexArray(vao[1]);
	glDrawArrays(GL_TRIANGLES, 0, cylinder_vertexes);
}


const int tree_grid = 2;

const int Numi = tree_grid*tree_grid;

/*                    SPHERE                  */
/*                    PAINT                    */
void paint_sphere()
{
	glUseProgram(program[sphere]);

	// Initialize shader lighting parameters
	color4 light_ambient(0.2, 0.2, 0.2, 1.0);
	color4 light_diffuse(1.0, 1.0, 1.0, 1.0);
	color4 light_specular(1.0, 1.0, 1.0, 1.0);

	color4 material_ambient(1, 1, 1, 1.0);
	color4 material_diffuse(1, 1, 1, 1.0);
	color4 material_specular(1, 1, 1, 1.0);
	float  material_shininess = 51.2;
	if (glGetUniformLocation)
	{
		glGetUniformLocation(program[sphere], "LightPosition2");

	}
	else
	{

		std::cout << "BYEEEEEEE" << std::endl;
	}


	color4 ambient_product = productComponentwise(light_ambient, material_ambient);
	color4 diffuse_product = productComponentwise(light_diffuse, material_diffuse);
	color4 specular_product = productComponentwise(light_specular, material_specular);

	point4 spin_to_win = vec4(-3 * sin(spin), 12, -3 * cos(spin), 1.0);

	glUniform4fv(glGetUniformLocation(program[sphere], "AmbientProduct"),
		1, ambient_product);
	glUniform4fv(glGetUniformLocation(program[sphere], "DiffuseProduct"),
		1, diffuse_product);
	glUniform4fv(glGetUniformLocation(program[sphere], "SpecularProduct"),
		1, specular_product);

	glUniform4fv(glGetUniformLocation(program[sphere], "AmbientProduct2"),
		1, ambient_product);
	glUniform4fv(glGetUniformLocation(program[sphere], "DiffuseProduct2"),
		1, diffuse_product);
	glUniform4fv(glGetUniformLocation(program[sphere], "SpecularProduct2"),
		1, specular_product);

	glUniform4fv(glGetUniformLocation(program[sphere], "LightPosition"),
		1, spin_to_win);

	glUniform4fv(glGetUniformLocation(program[sphere], "LightPosition2"),
		1, eye - vec4(1.0, 1.0, 0, 0));

	glUniform4fv(glGetUniformLocation(program[sphere], "LightPosition3"),
		1, scene_light_pos);

	glUniform4fv(glGetUniformLocation(program[sphere], "AmbientProduct3"),
		1, ambient_product);
	glUniform4fv(glGetUniformLocation(program[sphere], "DiffuseProduct3"),
		1, diffuse_product);
	glUniform4fv(glGetUniformLocation(program[sphere], "SpecularProduct3"),
		1, specular_product);


	glUniform1f(glGetUniformLocation(program[sphere], "Shininess"),
		material_shininess);

	Projection = glGetUniformLocation(program[sphere], "Projection");
	ModelView = glGetUniformLocation(program[sphere], "ModelView");


	glUniformMatrix4fv(Projection, 1, GL_TRUE, projmat);
	glUniformMatrix4fv(ModelView, 1, GL_TRUE, model_view);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textures[0]);

	glBindVertexArray(vao[0]);
	glDrawArraysInstanced(GL_TRIANGLES, 0, num_vertexes,Numi);
}





void paint_ellipse()
{
	glUseProgram(program[ellipse]);

	// Initialize shader lighting parameters
	color4 light_ambient(0.2, 0.2, 0.2, 1.0);
	color4 light_diffuse(1.0, 1.0, 1.0, 1.0);
	color4 light_specular(1.0, 1.0, 1.0, 1.0);
	float  material_shininess = 51.2;

	color4 material_ambient(1, 1, 1, 1.0);
	color4 material_diffuse(1, 1, 1, 1.0);
	color4 material_specular(1, 1, 1, 1.0);

	color4 ambient_product = productComponentwise(light_ambient, material_ambient);
	color4 diffuse_product = productComponentwise(light_diffuse, material_diffuse);
	color4 specular_product = productComponentwise(light_specular, material_specular);

	point4 spin_to_win = vec4(-3 * sin(spin), 12, -3 * cos(spin), 1.0);

	glUniform4fv(glGetUniformLocation(program[ellipse], "AmbientProduct"),
		1, ambient_product);
	glUniform4fv(glGetUniformLocation(program[ellipse], "DiffuseProduct"),
		1, diffuse_product);
	glUniform4fv(glGetUniformLocation(program[ellipse], "SpecularProduct"),
		1, specular_product);

	glUniform4fv(glGetUniformLocation(program[ellipse], "AmbientProduct2"),
		1, ambient_product);
	glUniform4fv(glGetUniformLocation(program[ellipse], "DiffuseProduct2"),
		1, diffuse_product);
	glUniform4fv(glGetUniformLocation(program[ellipse], "SpecularProduct2"),
		1, specular_product);

	glUniform4fv(glGetUniformLocation(program[ellipse], "AmbientProduct3"),
		1, ambient_product);
	glUniform4fv(glGetUniformLocation(program[ellipse], "DiffuseProduct3"),
		1, diffuse_product);
	glUniform4fv(glGetUniformLocation(program[ellipse], "SpecularProduct3"),
		1, specular_product);

	glUniform4fv(glGetUniformLocation(program[sphere], "LightPosition"),
		1, spin_to_win);

	glUniform4fv(glGetUniformLocation(program[sphere], "LightPosition2"),
		1, eye - vec4(1.0, 1.0, 0, 0));

	glUniform4fv(glGetUniformLocation(program[sphere], "LightPosition3"),
		1, scene_light_pos);

	glUniform1f(glGetUniformLocation(program[ellipse], "Shininess"),
		material_shininess);

	Projection = glGetUniformLocation(program[ellipse], "Projection");
	ModelView = glGetUniformLocation(program[ellipse], "ModelView");
	glUniformMatrix4fv(Projection, 1, GL_TRUE, projmat);
	glUniformMatrix4fv(ModelView, 1, GL_TRUE, model_view);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textures[2]);

	glBindVertexArray(vao[2]);
	glDrawArrays(GL_TRIANGLES, 0, num_vertexes);
}

void init_pop()
{
	make_sphere();
	make_cylinder();
}



void init()
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	cyllMesh();

	//IMAGE4 = glmReadPPM("road.ppm", &TextureWidth[0], &TextureHeight[0]);

	//======== Initialization for the road =============

	buildRoad();

	IMAGE4 = glmReadPPM("dirtroad.ppm", &TextureWidth[4], &TextureHeight[4]);


	glActiveTexture(GL_TEXTURE0); //See p 469 Red Book 7th ed
	glBindTexture(GL_TEXTURE_2D, texturesROAD[4]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, TextureWidth[4], TextureHeight[4], 0,
		GL_RGB, GL_UNSIGNED_BYTE, IMAGE4);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glActiveTexture(GL_TEXTURE0);

	glBindTexture(GL_TEXTURE_2D, textures[2]);


	if (!GLEW_ARB_vertex_array_object)
		std::cerr << "ARB_vertex_array_object not available." << std::endl;

	glGenVertexArrays(1, &Gvao);

	// Create and initialize a gBuffer object
	GLuint gBuffer;
	glGenBuffers(1, &gBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, gBuffer);
	glBufferData(GL_ARRAY_BUFFER,
		sizeof(POINTSS) + sizeof(quad_Normal) + sizeof(TEXT_CORRDS),
		NULL, GL_STATIC_DRAW);
	glBindVertexArray(Gvao);
	// Specify an offset to keep track of where we're placing data in our
	//   vertex array gBuffer.  We'll use the same technique when we
	//   associate the offsets with vertex attribute pointers.
	GLintptr offset = 0;
	glBufferSubData(GL_ARRAY_BUFFER, offset, sizeof(POINTSS), POINTSS);
	offset += sizeof(POINTSS);

	glBufferSubData(GL_ARRAY_BUFFER_ARB, offset,
		sizeof(quad_Normal), quad_Normal);
	offset += sizeof(quad_Normal);

	glBufferSubData(GL_ARRAY_BUFFER, offset, sizeof(TEXT_CORRDS), TEXT_CORRDS);

	// Load shaders and use the resulting shader GProgram
	GProgram[road] = InitShader("shadedTM_vert.glsl", "shadedTM_frag.glsl");
	glUseProgram(GProgram[road]);

	// set up vertex arrays
	offset = 0;
	vPosition = glGetAttribLocation(GProgram[road], "vertex");
	glEnableVertexAttribArray(vPosition);
	glVertexAttribPointer(vPosition, 4, GL_FLOAT, GL_FALSE, 0,
		BUFFER_OFFSET(offset));
	offset += sizeof(POINTSS);

	vNormal = glGetAttribLocation(GProgram[road], "normal");
	glEnableVertexAttribArray(vNormal);
	glVertexAttribPointer(vNormal, 3, GL_FLOAT, GL_FALSE, 0,
		BUFFER_OFFSET(offset));
	offset += sizeof(quad_Normal);

	vTexCoord = glGetAttribLocation(GProgram[road], "vTexCoord");
	glEnableVertexAttribArray(vTexCoord);
	glVertexAttribPointer(vTexCoord, 2, GL_FLOAT, GL_FALSE, 0,
		BUFFER_OFFSET(offset));

	glUniform1i(glGetUniformLocation(GProgram[road], "texture"), 0);


	glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glClearColor(1.0, 1.0, 1.0, 1.0);


	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	glGenBuffers(4, sBuffers);
	//Vertex buffer for the vertex coordinates
	glBindBuffer(GL_ARRAY_BUFFER, sBuffers[cube_vertices]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, sBuffers[cube_vertices_explicit]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cube_vertices_positions), cube_vertices_positions, GL_STATIC_DRAW);

	std::cout << "sizeof(cube_vertices_positions)" << sizeof(cube_vertices_positions) << std::endl;

	//Elements buffer for the pointers
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, sBuffers[cube_indeces]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glGenVertexArrays(2, VAO);

	// Load shaders and use the resulting shader sPrograms
	sProgram[0] = InitShader("./shaders/vshader30_TwoCubes_FullPipe.glsl", "./shaders/fshader30_TwoCubes.glsl");
	sProgram[1] = InitShader("./shaders/skyboxvertex.glsl", "./shaders/skyboxfragment.glsl");


	//VAO[1] the skybox
	glUseProgram(sProgram[1]);
	glBindVertexArray(VAO[1]);
	glBindBuffer(GL_ARRAY_BUFFER, sBuffers[cube_vertices_explicit]);
	vPosition = glGetAttribLocation(sProgram[1], "vPosition");
	glEnableVertexAttribArray(vPosition);
	glVertexAttribPointer(vPosition, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	//done with this packet
	glBindVertexArray(0);
	glUseProgram(0);

	//VAO[0] the Cube 
	glUseProgram(sProgram[0]);

	glBindVertexArray(VAO[0]);
	glBindBuffer(GL_ARRAY_BUFFER, sBuffers[cube_vertices]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, sBuffers[cube_indeces]);
	vPosition = glGetAttribLocation(sProgram[0], "vPosition");
	glEnableVertexAttribArray(vPosition);
	glVertexAttribPointer(vPosition, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	//done with this packet
	glBindVertexArray(0);

	glUseProgram(0);

	//Skybox textures 

	//Load Skybox Images. 6 images to represent the 6 angles of view. Inside it's own structured Cubemap
	skybox.top = glmReadPPM("skybox\\sun.ppm", &skybox.topWidth, &skybox.topHeight);//sky-top.ppm
	skybox.bottom = glmReadPPM("skybox\\sea.ppm", &skybox.bottomWidth, &skybox.bottomHeight);//skybox\\sky-bottom.ppm
	skybox.right = glmReadPPM("skybox\\psky.ppm", &skybox.rightWidth, &skybox.rightHeight);//sky-right.ppm
	skybox.left = glmReadPPM("skybox\\psky.ppm", &skybox.leftWidth, &skybox.leftHeight);//sky-left.ppm
	skybox.front = glmReadPPM("skybox\\psky.ppm", &skybox.frontWidth, &skybox.frontHeight);//sky-front.ppm
	skybox.back = glmReadPPM("skybox\\psky.ppm", &skybox.backWidth, &skybox.backHeight);//sky-back.ppm

	glActiveTexture(GL_TEXTURE0);

	glGenTextures(1, &texture);

	int isEnabled = 0;

	if (glIsEnabled(GL_TEXTURE_CUBE_MAP) == GL_TRUE) { isEnabled = 1; }
	else { isEnabled = 0; };


	std::cout << isEnabled << std::endl;

	glEnable(GL_TEXTURE_CUBE_MAP);


	if (glIsEnabled(GL_TEXTURE_CUBE_MAP) == GL_TRUE) { isEnabled = 1; }
	else { isEnabled = 0; };

	std::cout << isEnabled << std::endl;


	glBindTexture(GL_TEXTURE_CUBE_MAP, texture);
	glTexParameterf(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameterf(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameterf(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_GENERATE_MIPMAP, GL_TRUE);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0, GL_RGB, skybox.topWidth, skybox.topHeight, 0,
		GL_RGB, GL_UNSIGNED_BYTE, skybox.top);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, GL_RGB, skybox.bottomWidth, skybox.bottomHeight, 0,
		GL_RGB, GL_UNSIGNED_BYTE, skybox.bottom);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X, 0, GL_RGB, skybox.rightWidth, skybox.rightHeight, 0,
		GL_RGB, GL_UNSIGNED_BYTE, skybox.right);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, 0, GL_RGB, skybox.leftWidth, skybox.rightWidth, 0,
		GL_RGB, GL_UNSIGNED_BYTE, skybox.left);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 0, GL_RGB, skybox.frontWidth, skybox.frontHeight, 0,
		GL_RGB, GL_UNSIGNED_BYTE, skybox.front);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, GL_RGB, skybox.backWidth, skybox.backHeight, 0,
		GL_RGB, GL_UNSIGNED_BYTE, skybox.back);
	glGenerateMipmap(GL_TEXTURE_CUBE_MAP);


	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClearDepth(1.0);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////sky box
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	glGenVertexArrays(30, vao);
	glGenBuffers(20, buffers);
	glGenTextures(30, textures);

	image0 = glmReadPPM("toptree.ppm", &TextureWidth[0], &TextureHeight[0]);
	image1 = glmReadPPM("brks.ppm", &TextureWidth[1], &TextureHeight[1]);
	image2 = glmReadPPM("copper_texture256by256.ppm", &TextureWidth[2], &TextureHeight[2]);//copper_texture256by256.ppm
	image3 = glmReadPPM("sasgrass.ppm", &TextureWidth[3], &TextureHeight[3]);


	/*                    SPHERE                  */
	/*                    INIT                   */


	program[sphere] = InitShader("vshader.glsl", "fshader.glsl");

	glBindVertexArray(vao[0]);

	glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, buffers[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(normals), normals, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, buffers[2]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(tex_coords), tex_coords, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
	vPosition = glGetAttribLocation(program[sphere], "vPosition");
	glEnableVertexAttribArray(vPosition);
	glVertexAttribPointer(vPosition, 4, GL_FLOAT, GL_FALSE, 0,
		BUFFER_OFFSET(nullptr));

	glBindBuffer(GL_ARRAY_BUFFER, buffers[1]);
	vNormal = glGetAttribLocation(program[sphere], "vNormal");
	glEnableVertexAttribArray(vNormal);
	glVertexAttribPointer(vNormal, 3, GL_FLOAT, GL_FALSE, 0,
		BUFFER_OFFSET(nullptr));

	glBindBuffer(GL_ARRAY_BUFFER, buffers[2]);
	vTexCoord = glGetAttribLocation(program[sphere], "vTexCoord");
	glEnableVertexAttribArray(vTexCoord);
	glVertexAttribPointer(vTexCoord, 2, GL_FLOAT, GL_FALSE, 0,
		BUFFER_OFFSET(nullptr));

	glUniform1i(glGetUniformLocation(program[sphere], "texture"), 0);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textures[0]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, TextureWidth[0], TextureHeight[0], 0,
		GL_RGB, GL_UNSIGNED_BYTE, image0);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	if (!GLEW_ARB_vertex_array_object)
		std::cerr << "ARB_vertex_array_object not available." << std::endl;

	/*                    GROUND               */
	/*                    INIT                   */

	program[ground] = InitShader("vshader.glsl", "fshader.glsl");

	glBindVertexArray(vao[1]);

	glBindBuffer(GL_ARRAY_BUFFER, buffers[3]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cylinderData), cylinderData, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, buffers[4]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cylinderData), cylinderData, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, buffers[5]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(tex_coords), tex_coords, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, buffers[3]);
	vPosition = glGetAttribLocation(program[ground], "vPosition");
	glEnableVertexAttribArray(vPosition);
	glVertexAttribPointer(vPosition, 4, GL_FLOAT, GL_FALSE, 0,
		BUFFER_OFFSET(nullptr));

	glBindBuffer(GL_ARRAY_BUFFER, buffers[4]);
	vNormal = glGetAttribLocation(program[ground], "vNormal");
	glEnableVertexAttribArray(vNormal);
	glVertexAttribPointer(vNormal, 4, GL_FLOAT, GL_FALSE, 0,
		BUFFER_OFFSET(nullptr));

	glBindBuffer(GL_ARRAY_BUFFER, buffers[5]);
	vTexCoord = glGetAttribLocation(program[ground], "vTexCoord");
	glEnableVertexAttribArray(vTexCoord);
	glVertexAttribPointer(vTexCoord, 2, GL_FLOAT, GL_FALSE, 0,
		BUFFER_OFFSET(nullptr));

	glUniform1i(glGetUniformLocation(program[ground], "texture"), 0);

	glBindTexture(GL_TEXTURE_2D, textures[3]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, TextureWidth[3], TextureHeight[3], 0,
		GL_RGB, GL_UNSIGNED_BYTE, image3);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	/*                    CYLINDER                 */
	/*                    INIT                   */

	program[cylinder] = InitShader("vshader.glsl", "fshader.glsl");

	glBindVertexArray(vao[1]);

	glBindBuffer(GL_ARRAY_BUFFER, buffers[6]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cylinderData), cylinderData, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, buffers[7]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cylinderData), cylinderData, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, buffers[8]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(tex_coords), tex_coords, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, buffers[6]);
	vPosition = glGetAttribLocation(program[cylinder], "vPosition");
	glEnableVertexAttribArray(vPosition);
	glVertexAttribPointer(vPosition, 4, GL_FLOAT, GL_FALSE, 0,
		BUFFER_OFFSET(nullptr));

	glBindBuffer(GL_ARRAY_BUFFER, buffers[7]);
	vNormal = glGetAttribLocation(program[cylinder], "vNormal");
	glEnableVertexAttribArray(vNormal);
	glVertexAttribPointer(vNormal, 4, GL_FLOAT, GL_FALSE, 0,
		BUFFER_OFFSET(nullptr));

	glBindBuffer(GL_ARRAY_BUFFER, buffers[8]);
	vTexCoord = glGetAttribLocation(program[cylinder], "vTexCoord");
	glEnableVertexAttribArray(vTexCoord);
	glVertexAttribPointer(vTexCoord, 2, GL_FLOAT, GL_FALSE, 0,
		BUFFER_OFFSET(nullptr));

	glUniform1i(glGetUniformLocation(program[cylinder], "texture"), 0);

	glBindTexture(GL_TEXTURE_2D, textures[1]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, TextureWidth[1], TextureHeight[1], 0,
		GL_RGB, GL_UNSIGNED_BYTE, image1);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);


	/*                    ELLIPSE                  */
	/*                    INIT                   */

	program[ellipse] = InitShader("vshader.glsl", "fshader.glsl");

	glBindVertexArray(vao[2]);

	glBindBuffer(GL_ARRAY_BUFFER, buffers[9]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, buffers[10]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(normals), normals, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, buffers[11]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(tex_coords), tex_coords, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, buffers[9]);
	vPosition = glGetAttribLocation(program[ellipse], "vPosition");
	glEnableVertexAttribArray(vPosition);
	glVertexAttribPointer(vPosition, 4, GL_FLOAT, GL_FALSE, 0,
		BUFFER_OFFSET(nullptr));

	glBindBuffer(GL_ARRAY_BUFFER, buffers[10]);
	vNormal = glGetAttribLocation(program[ellipse], "vNormal");
	glEnableVertexAttribArray(vNormal);
	glVertexAttribPointer(vNormal, 3, GL_FLOAT, GL_FALSE, 0,
		BUFFER_OFFSET(nullptr));

	glBindBuffer(GL_ARRAY_BUFFER, buffers[11]);
	vTexCoord = glGetAttribLocation(program[ellipse], "vTexCoord");
	glEnableVertexAttribArray(vTexCoord);
	glVertexAttribPointer(vTexCoord, 2, GL_FLOAT, GL_FALSE, 0,
		BUFFER_OFFSET(nullptr));


	glUniform1i(glGetUniformLocation(program[ellipse], "texture"), 0);

	glBindTexture(GL_TEXTURE_2D, textures[2]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, TextureWidth[2], TextureHeight[2], 0,
		GL_RGB, GL_UNSIGNED_BYTE, image2);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glBindVertexArray(0);
	glUseProgram(0);


	/*                    CUBE                   */
	/*                    INIT                   */
	program[road] = InitShader("vshader.glsl", "fshader.glsl");

	glBindBuffer(GL_ARRAY_BUFFER, buffers[12]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(roadData), roadData, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, buffers[13]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(roadNormals), roadNormals, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, buffers[14]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(roadTexCoords), roadTexCoords, GL_STATIC_DRAW);

	glBindVertexArray(vao[1]);//changing the vao helps

	glBindBuffer(GL_ARRAY_BUFFER, buffers[12]);
	vPosition = glGetAttribLocation(program[road], "vPosition");
	glEnableVertexAttribArray(vPosition);
	glVertexAttribPointer(vPosition, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	glBindBuffer(GL_ARRAY_BUFFER, buffers[13]);
	vNormal = glGetAttribLocation(program[road], "vNormal");
	glEnableVertexAttribArray(vNormal);
	glVertexAttribPointer(vNormal, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	glBindBuffer(GL_ARRAY_BUFFER, buffers[14]);
	vTexCoord = glGetAttribLocation(program[road], "vTexCoord");
	glEnableVertexAttribArray(vTexCoord);
	glVertexAttribPointer(vTexCoord, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	// Road texture stuff

	glBindTexture(GL_TEXTURE_2D, textures[1]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, TextureWidth[4], TextureHeight[4], 0,
		GL_RGB, GL_UNSIGNED_BYTE, IMAGE4);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);


	glActiveTexture(GL_TEXTURE0);


	initNodes();

	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClearDepth(1.0);
}

/*                    KEYBOARD                  */
/*                    FUNCTIONS                 */
bool flip = true;
void
keyboard(unsigned char key, int x, int y)
{
	GLfloat xt, yt, zt;
	GLfloat cosine, sine;
	if (key == 32)
	{
		v = vec4(0.0, 1.0, 0.0, 00);
		u = vec4(1.0, 0.0, 0.0, 0.0);
		eye = vec4(0.0, 1.5, 3.0, 1.0);

		n = Angel::normalize(vec4(0.0, 0.0, 1.0, 0.0));
	}
	if (key > 96)
	{
		cosine = cos(PI / -180.0);
		sine = sin(PI / -180.0);
	}
	else
	{
		cosine = cos(PI / 180.0);
		sine = sin(PI / 180.0);
	}

	switch (key)
	{
	case 'x': // pitch up
	case 'X': // pitch down
		xt = v[0];
		yt = v[1];
		zt = v[2];

		v[0] = xt*cosine - sine*n[0];
		v[1] = yt*cosine - sine*n[1];
		v[2] = zt*cosine - sine*n[2];
		n[0] = xt*sine + cosine*n[0];
		n[1] = yt*sine + cosine*n[1];
		n[2] = zt*sine + cosine*n[2];
		break;
	case 'Z': // roll numbererclockwise in the xy plane
	case 'z': // roll clockwise in the xy plane
		xt = u[0];
		yt = u[1];
		zt = u[2];
		u[0] = xt*cosine - v[0] * sine;
		u[1] = yt*cosine - v[1] * sine;
		u[2] = zt*cosine - v[2] * sine;
		v[0] = xt*sine + v[0] * cosine;
		v[1] = yt*sine + v[1] * cosine;
		v[2] = zt*sine + v[2] * cosine;
		break;

	case 'c': // yaw numberer-clockwise
	case 'C': // yaw clockwise
		xt = u[0];
		yt = u[1];
		zt = u[2];

		u[0] = xt*cosine - sine*n[0];
		u[1] = yt*cosine - sine*n[1];
		u[2] = zt*cosine - sine*n[2];
		n[0] = xt*sine + cosine*n[0];
		n[1] = yt*sine + cosine*n[1];
		n[2] = zt*sine + cosine*n[2];
		break;

	case 'v': // yaw numberer-clockwise
	case 'V': // yaw clockwise
		if (flip)
			eye = vec4(eye.x, 11, eye.z, 1.0);
		else
			eye = vec4(eye.x, 1.5, eye.z, 1.0); ;

		flip = !flip;

		fputs(flip ? "true" : "false", stdout);
		break;
	case 033:  // Escape key
	case 'q': case 'Q':
		exit(EXIT_SUCCESS);
	}

	glutPostRedisplay();
}


void specKey(int key, int x, int y)
{
	switch (key) {
	case GLUT_KEY_UP: // MOVE FORWARD
		eye[0] -= n[0];
		//eye[1] -= n[1];
		eye[2] -= n[2];


		break;

	case GLUT_KEY_DOWN: // MOVE BACKWARD
		eye[0] += n[0];
		//eye[1] += n[1];
		eye[2] += n[2];
		break;

	case GLUT_KEY_LEFT: // MOVE FORWARD
		eye[0] -= u[0];
		eye[1] -= u[1];
		eye[2] -= u[2];

		
		break;

	case GLUT_KEY_RIGHT: // MOVE BACKWARD
		eye[0] += u[0];
		eye[1] += u[1];
		eye[2] += u[2];

		
		break;

	default:
		break;
	}
	glutPostRedisplay();
}

void
reshape(int width, int height)
{
	glViewport(0, 0, width, height);

	GLfloat left = -2.0, right = 2.0;
	GLfloat top = 2.0, bottom = -2.0;
	GLfloat zNear = -20.0, zFar = 20.0;

	GLfloat aspect = GLfloat(width) / height;

	if (aspect > 1.0) {
		left *= aspect;
		right *= aspect;
	}
	else {
		top /= aspect;
		bottom /= aspect;
	}

	mat4 projection = Ortho(left, right, bottom, top, zNear, zFar);
	glUniformMatrix4fv(Projection, 1, GL_TRUE, projection);
}


bool near_village = false;
void
display(void)
{

	draw_road();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	projmat = Perspective(60, 1.0, 1.0, 100);//60, 1.0, 1.0, 40.0

	modelviewStackBottom = model_view; //mvstack.push


		glUseProgram(sProgram[0]);
	color_loc = glGetUniformLocation(sProgram[0], "color");
	proj_loc = glGetUniformLocation(sProgram[0], "projection");
	model_view_loc = glGetUniformLocation(sProgram[0], "modelview");
	glUniformMatrix4fv(proj_loc, 1, GL_TRUE, projmat);

	glUniformMatrix4fv(model_view_loc, 1, GL_TRUE, model_view*Translate(13, -2.67, -30)*Scale(10, 5, 10));//10, -2.67, -30


	glUniform4fv(color_loc, 1, blue_transparent);//

	glPolygonOffset(1.0, 1.0);
	glBindVertexArray(VAO[0]);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, BUFFER_OFFSET(0));



	//Sky Box @  infinity
	vec4 skyboxEye = vec4(0.0, 0.0, 0.0, 1.0);//0.0, -0.8, 0.8, 1.0
	model_view = LookAt(skyboxEye, skyboxEye - n, v);

	glUseProgram(sProgram[1]);
	proj_loc = glGetUniformLocation(sProgram[1], "Projection");
	model_view_loc = glGetUniformLocation(sProgram[1], "ModelView");
	glUniformMatrix4fv(proj_loc, 1, GL_TRUE, projmat);
	glUniformMatrix4fv(model_view_loc, 1, GL_TRUE, model_view);
	glUniform1i(glGetUniformLocation(sProgram[1], "CubeMap"), 0);

	glBindVertexArray(VAO[1]);

	glCullFace(GL_BACK);
	glDisable(GL_DEPTH_TEST);
	glDepthMask(GL_FALSE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glDrawArrays(GL_QUADS, 0, 24);

	glEnable(GL_DEPTH_TEST);

	glDepthMask(GL_TRUE);


	glUseProgram(0);

	model_view = Angel::mat4(1.0);

	//Render the  rest of the scene

	//Position and orient the camera
	model_view = model_view;//LookAt(eye, eye - n, v)*      *Translate(0,0,)


	model_view = Angel::mat4(1.0);

	model_view = model_view* LookAt(eye, eye - n, v);
	model_view = model_view*Translate(0, 0, 0);

	modelviewStackBottom = model_view; //mvstack.push

	model_view = model_view**Scale(2, 2, 2);
	///////////////////////////////////////////////////////////////////////////////
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(sProgram[0]);
	color_loc = glGetUniformLocation(sProgram[0], "color");
	proj_loc = glGetUniformLocation(sProgram[0], "projection");
	model_view_loc = glGetUniformLocation(sProgram[0], "modelview");
	glUniformMatrix4fv(proj_loc, 1, GL_TRUE, projmat);

	double z = .1;

		if (flip)
		{
			glUniformMatrix4fv(model_view_loc, 1, GL_TRUE, model_view*Translate(eye.x, 11, eye.z)*Scale(10, 1, 20));//

		}
		else
		{
			glUniformMatrix4fv(model_view_loc, 1, GL_TRUE, model_view*Translate(eye.x, -5 * z, eye.z)*Scale(1, 1, 2));//

		}
	
	//glUniformMatrix4fv(model_view_loc, 1, GL_TRUE, model_view*Translate(.5,1.0,(-5*z))*Scale(1,1,2));
	glUniform4fv(color_loc, 1, blue_transparent);

	glPolygonOffset(1.0, 1.0);
	glBindVertexArray(VAO[0]);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, BUFFER_OFFSET(0));

	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(sProgram[0]);
	color_loc = glGetUniformLocation(sProgram[0], "color");
	proj_loc = glGetUniformLocation(sProgram[0], "projection");
	model_view_loc = glGetUniformLocation(sProgram[0], "modelview");
	glUniformMatrix4fv(proj_loc, 1, GL_TRUE, projmat);
	glUniformMatrix4fv(model_view_loc, 1, GL_TRUE, model_view*Translate(-8, 1.0, -138)*Scale(3, 3, 3));
	glUniform4fv(color_loc, 1, brown_transparent);

	glPolygonOffset(1.0, 1.0);
	glBindVertexArray(VAO[0]);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, BUFFER_OFFSET(0));

	///////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(sProgram[0]);
	color_loc = glGetUniformLocation(sProgram[0], "color");
	proj_loc = glGetUniformLocation(sProgram[0], "projection");
	model_view_loc = glGetUniformLocation(sProgram[0], "modelview");
	glUniformMatrix4fv(proj_loc, 1, GL_TRUE, projmat);
	glUniformMatrix4fv(model_view_loc, 1, GL_TRUE, model_view*Translate(-8, 3, -138)*Scale(4, 1, 4));
	glUniform4fv(color_loc, 1, red_transparent);

	glPolygonOffset(1.0, 1.0);
	glBindVertexArray(VAO[0]);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, BUFFER_OFFSET(0));
	///////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(sProgram[0]);
	color_loc = glGetUniformLocation(sProgram[0], "color");
	proj_loc = glGetUniformLocation(sProgram[0], "projection");
	model_view_loc = glGetUniformLocation(sProgram[0], "modelview");
	glUniformMatrix4fv(proj_loc, 1, GL_TRUE, projmat);
	glUniformMatrix4fv(model_view_loc, 1, GL_TRUE, model_view*Translate(-4, 1.0, -148)*Scale(3, 3, 3));
	glUniform4fv(color_loc, 1, brown_transparent);

	glPolygonOffset(1.0, 1.0);
	glBindVertexArray(VAO[0]);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, BUFFER_OFFSET(0));


	///////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(sProgram[0]);
	color_loc = glGetUniformLocation(sProgram[0], "color");
	proj_loc = glGetUniformLocation(sProgram[0], "projection");
	model_view_loc = glGetUniformLocation(sProgram[0], "modelview");
	glUniformMatrix4fv(proj_loc, 1, GL_TRUE, projmat);
	glUniformMatrix4fv(model_view_loc, 1, GL_TRUE, model_view*Translate(-4, 3, -148)*Scale(4, 1, 4));
	glUniform4fv(color_loc, 1, red_transparent);

	glPolygonOffset(1.0, 1.0);
	glBindVertexArray(VAO[0]);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, BUFFER_OFFSET(0));

	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(sProgram[0]);
	color_loc = glGetUniformLocation(sProgram[0], "color");
	proj_loc = glGetUniformLocation(sProgram[0], "projection");
	model_view_loc = glGetUniformLocation(sProgram[0], "modelview");
	glUniformMatrix4fv(proj_loc, 1, GL_TRUE, projmat);
	glUniformMatrix4fv(model_view_loc, 1, GL_TRUE, model_view*Translate(-3.5, 1.0, -158)*Scale(3, 3, 3));
	glUniform4fv(color_loc, 1, brown_transparent);

	glPolygonOffset(1.0, 1.0);
	glBindVertexArray(VAO[0]);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, BUFFER_OFFSET(0));


	///////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(sProgram[0]);
	color_loc = glGetUniformLocation(sProgram[0], "color");
	proj_loc = glGetUniformLocation(sProgram[0], "projection");
	model_view_loc = glGetUniformLocation(sProgram[0], "modelview");
	glUniformMatrix4fv(proj_loc, 1, GL_TRUE, projmat);
	glUniformMatrix4fv(model_view_loc, 1, GL_TRUE, model_view*Translate(-3.5, 3, -158)*Scale(4, 1, 4));
	glUniform4fv(color_loc, 1, red_transparent);

	glPolygonOffset(1.0, 1.0);
	glBindVertexArray(VAO[0]);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, BUFFER_OFFSET(0));


	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(sProgram[0]);
	color_loc = glGetUniformLocation(sProgram[0], "color");
	proj_loc = glGetUniformLocation(sProgram[0], "projection");
	model_view_loc = glGetUniformLocation(sProgram[0], "modelview");
	glUniformMatrix4fv(proj_loc, 1, GL_TRUE, projmat);
	glUniformMatrix4fv(model_view_loc, 1, GL_TRUE, model_view*Translate(8, 1.0, -138)*Scale(3, 3, 3));
	glUniform4fv(color_loc, 1, brown_transparent);

	glPolygonOffset(1.0, 1.0);
	glBindVertexArray(VAO[0]);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, BUFFER_OFFSET(0));

	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(sProgram[0]);
	color_loc = glGetUniformLocation(sProgram[0], "color");
	proj_loc = glGetUniformLocation(sProgram[0], "projection");
	model_view_loc = glGetUniformLocation(sProgram[0], "modelview");
	glUniformMatrix4fv(proj_loc, 1, GL_TRUE, projmat);
	glUniformMatrix4fv(model_view_loc, 1, GL_TRUE, model_view*Translate(8, 3, -138)*Scale(4, 1, 4));
	glUniform4fv(color_loc, 1, red_transparent);

	glPolygonOffset(1.0, 1.0);
	glBindVertexArray(VAO[0]);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, BUFFER_OFFSET(0));
	///////////////////////////////////////////////////////////////////////////////

	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(sProgram[0]);
	color_loc = glGetUniformLocation(sProgram[0], "color");
	proj_loc = glGetUniformLocation(sProgram[0], "projection");
	model_view_loc = glGetUniformLocation(sProgram[0], "modelview");
	glUniformMatrix4fv(proj_loc, 1, GL_TRUE, projmat);
	glUniformMatrix4fv(model_view_loc, 1, GL_TRUE, model_view*Translate(6, 1.0, -148)*Scale(3, 3, 3));
	glUniform4fv(color_loc, 1, brown_transparent);

	glPolygonOffset(1.0, 1.0);
	glBindVertexArray(VAO[0]);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, BUFFER_OFFSET(0));

	///////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(sProgram[0]);
	color_loc = glGetUniformLocation(sProgram[0], "color");
	proj_loc = glGetUniformLocation(sProgram[0], "projection");
	model_view_loc = glGetUniformLocation(sProgram[0], "modelview");
	glUniformMatrix4fv(proj_loc, 1, GL_TRUE, projmat);
	glUniformMatrix4fv(model_view_loc, 1, GL_TRUE, model_view*Translate(6, 3, -148)*Scale(4, 1, 4));
	glUniform4fv(color_loc, 1, red_transparent);

	glPolygonOffset(1.0, 1.0);
	glBindVertexArray(VAO[0]);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, BUFFER_OFFSET(0));

	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(sProgram[0]);
	color_loc = glGetUniformLocation(sProgram[0], "color");
	proj_loc = glGetUniformLocation(sProgram[0], "projection");
	model_view_loc = glGetUniformLocation(sProgram[0], "modelview");
	glUniformMatrix4fv(proj_loc, 1, GL_TRUE, projmat);
	glUniformMatrix4fv(model_view_loc, 1, GL_TRUE, model_view*Translate(10, 1.0, -158)*Scale(3, 3, 3));
	glUniform4fv(color_loc, 1, brown_transparent);

	glPolygonOffset(1.0, 1.0);
	glBindVertexArray(VAO[0]);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, BUFFER_OFFSET(0));

	///////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(sProgram[0]);
	color_loc = glGetUniformLocation(sProgram[0], "color");
	proj_loc = glGetUniformLocation(sProgram[0], "projection");
	model_view_loc = glGetUniformLocation(sProgram[0], "modelview");
	glUniformMatrix4fv(proj_loc, 1, GL_TRUE, projmat);
	glUniformMatrix4fv(model_view_loc, 1, GL_TRUE, model_view*Translate(10, 3, -158)*Scale(4, 1, 4));
	glUniform4fv(color_loc, 1, red_transparent);

	glPolygonOffset(1.0, 1.0);
	glBindVertexArray(VAO[0]);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, BUFFER_OFFSET(0));

	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(sProgram[0]);
	color_loc = glGetUniformLocation(sProgram[0], "color");
	proj_loc = glGetUniformLocation(sProgram[0], "projection");
	model_view_loc = glGetUniformLocation(sProgram[0], "modelview");
	glUniformMatrix4fv(proj_loc, 1, GL_TRUE, projmat);
	glUniformMatrix4fv(model_view_loc, 1, GL_TRUE, model_view*Translate(7, 1.0, -158)*Scale(3, 3, 3));
	glUniform4fv(color_loc, 1, brown_transparent);

	glPolygonOffset(1.0, 1.0);
	glBindVertexArray(VAO[0]);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, BUFFER_OFFSET(0));

	///////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(sProgram[0]);
	color_loc = glGetUniformLocation(sProgram[0], "color");
	proj_loc = glGetUniformLocation(sProgram[0], "projection");
	model_view_loc = glGetUniformLocation(sProgram[0], "modelview");
	glUniformMatrix4fv(proj_loc, 1, GL_TRUE, projmat);
	glUniformMatrix4fv(model_view_loc, 1, GL_TRUE, model_view*Translate(7, 3, -158)*Scale(4, 1, 4));
	glUniform4fv(color_loc, 1, red_transparent);

	glPolygonOffset(1.0, 1.0);
	glBindVertexArray(VAO[0]);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, BUFFER_OFFSET(0));


	traverse(&nodes[0]);

	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(sProgram[0]);
	color_loc = glGetUniformLocation(sProgram[0], "color");
	proj_loc = glGetUniformLocation(sProgram[0], "projection");
	model_view_loc = glGetUniformLocation(sProgram[0], "modelview");
	glUniformMatrix4fv(proj_loc, 1, GL_TRUE, projmat);
	glUniformMatrix4fv(model_view_loc, 1, GL_TRUE, model_view*Translate(eye.x+.7, .1, eye.z-.5)*Scale(.5, .5, .5));
	glUniform4fv(color_loc, 1, black_transparent);

	glPolygonOffset(1.0, 1.0);
	glBindVertexArray(VAO[0]);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, BUFFER_OFFSET(0));
	///////////////////////////////////////////////////////////////////////////////
	traverse(&nodes[0]);

	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(sProgram[0]);
	color_loc = glGetUniformLocation(sProgram[0], "color");
	proj_loc = glGetUniformLocation(sProgram[0], "projection");
	model_view_loc = glGetUniformLocation(sProgram[0], "modelview");
	glUniformMatrix4fv(proj_loc, 1, GL_TRUE, projmat);
	glUniformMatrix4fv(model_view_loc, 1, GL_TRUE, model_view*Translate(eye.x - .7, .1, eye.z - .5)*Scale(.5, .5, .5));
	glUniform4fv(color_loc, 1, black_transparent);

	glPolygonOffset(1.0, 1.0);
	glBindVertexArray(VAO[0]);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, BUFFER_OFFSET(0));
	///////////////////////////////////////////////////////////////////////////////
	traverse(&nodes[0]);

	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(sProgram[0]);
	color_loc = glGetUniformLocation(sProgram[0], "color");
	proj_loc = glGetUniformLocation(sProgram[0], "projection");
	model_view_loc = glGetUniformLocation(sProgram[0], "modelview");
	glUniformMatrix4fv(proj_loc, 1, GL_TRUE, projmat);
	glUniformMatrix4fv(model_view_loc, 1, GL_TRUE, model_view*Translate(eye.x + .7, .1, eye.z + .5)*Scale(.5, .5, .5));
	glUniform4fv(color_loc, 1, black_transparent);

	glPolygonOffset(1.0, 1.0);
	glBindVertexArray(VAO[0]);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, BUFFER_OFFSET(0));
	///////////////////////////////////////////////////////////////////////////////
	traverse(&nodes[0]);

	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(sProgram[0]);
	color_loc = glGetUniformLocation(sProgram[0], "color");
	proj_loc = glGetUniformLocation(sProgram[0], "projection");
	model_view_loc = glGetUniformLocation(sProgram[0], "modelview");
	glUniformMatrix4fv(proj_loc, 1, GL_TRUE, projmat);
	glUniformMatrix4fv(model_view_loc, 1, GL_TRUE, model_view*Translate(eye.x - .7, .1, eye.z + .5)*Scale(.5, .5, .5));
	glUniform4fv(color_loc, 1, black_transparent);

	glPolygonOffset(1.0, 1.0);
	glBindVertexArray(VAO[0]);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, BUFFER_OFFSET(0));
	///////////////////////////////////////////////////////////////////////////////
	traverse(&nodes[0]);

	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(sProgram[0]);
	color_loc = glGetUniformLocation(sProgram[0], "color");
	proj_loc = glGetUniformLocation(sProgram[0], "projection");
	model_view_loc = glGetUniformLocation(sProgram[0], "modelview");
	glUniformMatrix4fv(proj_loc, 1, GL_TRUE, projmat);
	glUniformMatrix4fv(model_view_loc, 1, GL_TRUE, model_view*Translate(1, 1, -178.0)*Scale(6, 10, 2));
	glUniform4fv(color_loc, 1, black_transparent);

	glPolygonOffset(1.0, 1.0);
	glBindVertexArray(VAO[0]);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, BUFFER_OFFSET(0));
	///////////////////////////////////////////////////////////////////////////////
	traverse(&nodes[0]);


	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(sProgram[0]);
	color_loc = glGetUniformLocation(sProgram[0], "color");
	proj_loc = glGetUniformLocation(sProgram[0], "projection");
	model_view_loc = glGetUniformLocation(sProgram[0], "modelview");
	glUniformMatrix4fv(proj_loc, 1, GL_TRUE, projmat);



	glUniformMatrix4fv(model_view_loc, 1, GL_TRUE, model_view*Translate((eye.x), 1.5, (eye.z - .8))*Scale(2, 2, .2));
	glUniform4fv(color_loc, 1, slate_transparent);

	glPolygonOffset(1.0, 1.0);
	glBindVertexArray(VAO[0]);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, BUFFER_OFFSET(0));


	traverse(&nodes[0]);


	glutSwapBuffers();

}


void idle(void)
{
	spin += spin_step;

	glutPostRedisplay();
}



int main(int argc, char **argv) {
	init_pop();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(512, 512);
	glutCreateWindow("ALL OFF THE LIGHTS");

	glewInit();
	init();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specKey);
	glutIdleFunc(idle);
	
	glutMainLoop();
	return 0;
}