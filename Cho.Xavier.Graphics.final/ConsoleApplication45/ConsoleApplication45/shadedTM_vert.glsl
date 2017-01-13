#version 120

attribute vec4 vertex;
attribute vec3 normal;
attribute vec2 vTexCoord;

varying vec2 texCoord;
varying vec3 fN;
varying vec3 fE;
varying vec3 fL, fLL,FLLL;

uniform mat4 modelView;
uniform mat4 ModelViewObj;
uniform vec4 lightPosition, LightPosition2, LightPosition3;
uniform mat4 projection;
uniform mat4 normalTransformation;

void main()
{
  vec3 pos = (modelView*ModelViewObj*vertex).xyz;  
  fN = normalize((normalTransformation*vec4(normal,0.0)).xyz);
  fL = -((modelView*lightPosition).xyz);
  if (lightPosition.w != 0)
    {
      fL = (modelView*lightPosition).xyz - pos;
    }
  fE =-pos;
  gl_Position = projection*modelView*ModelViewObj*vertex;
  texCoord    = vTexCoord;
  
}
