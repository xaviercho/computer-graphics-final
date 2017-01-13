#version 120 

varying vec3 fN;
varying vec3 fL;
varying vec3 fE;

varying  vec2 texCoord;

uniform sampler2D texture;
uniform vec4 AmbientProduct;
uniform vec4 DiffuseProduct;
uniform vec4 SpecularProduct;
uniform float mat_shininess;

uniform vec4 light_ambient;
uniform vec4 light_diffuse;
uniform vec4 light_specular;


void main() 
{
  vec3 L = normalize(fL);
  vec3 E = normalize(fE);
  vec3 N = normalize(fN);
  vec3 H = normalize( L + E );
  vec4 ambient = AmbientProduct;
  float Kd = max(dot(L, N), 0.0);
  vec4 diffuse = Kd*DiffuseProduct;
  float Ks = pow(max(dot(N, H), 0.0), mat_shininess);
  vec4 specular = Ks*SpecularProduct;
  if( dot(L, N) < 0.0 )
    {
      specular = vec4(0.0, 0.0, 0.0, 1.0);
    }
  vec4 diffusePlusAmbient = ambient+diffuse;
 
  gl_FragColor = diffusePlusAmbient*texture2D(texture, texCoord ) +  specular;
  //gl_FragColor = diffusePlusAmbient*texture2D(texture, texCoord ) + ambient +  specular; //diffuse
  gl_FragColor.a = 1.0;
   
} 