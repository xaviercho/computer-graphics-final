#pragma once
#include "Header.h"


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




/*                    FUNCTIONS FOR                  */
/*                    PAINT                          */






/*                    CYLINDER                  */
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
	float  material_shininess = 51.2;

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
	glBindTexture(GL_TEXTURE_2D, textures[1]);

	glBindVertexArray(vao[1]);
	glDrawArrays(GL_TRIANGLES, 0, cylinder_vertexes);
}


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
	glDrawArrays(GL_TRIANGLES, 0, num_vertexes);
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