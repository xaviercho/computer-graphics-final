#version 120 


// per-fragment interpolated values from the vertex shader
varying  vec3 fN;
varying  vec3 fL, fL2, fL3;
varying  vec3 fE;
varying  vec2 texCoord;



uniform vec4 AmbientProduct, AmbientProduct2, AmbientProduct3;
uniform vec4 DiffuseProduct, DiffuseProduct2, DiffuseProduct3;
uniform vec4 SpecularProduct, SpecularProduct2, SpecularProduct3;
uniform mat4 ModelView;
uniform vec4 LightPosition, LightPosition2, LightPosition3;
uniform float Shininess;
uniform sampler2D texture;

void main() 
{ 
    // Normalize the input lighting vectors
    vec3 N = normalize(fN);
    vec3 E = normalize(fE);
    vec3 L = normalize(fL);
    vec3 L2 = normalize(fL2);
    vec3 L3 = normalize(fL3);
    
    vec3 H;
    vec4 ambient;
    float Kd;
    vec4 diffuse;
    float Ks;
    vec4 specular;
    
    vec3 lights[3];
    lights[0]=L;
    lights[1]=L2;
    lights[2]=L3;
    
    vec4 ambients[3];
    ambients[0]= AmbientProduct;
    ambients[1]= AmbientProduct2;
    ambients[2]= AmbientProduct3;
    
    vec4 diffuses[3];
    diffuses[0]= DiffuseProduct;
    diffuses[1]= DiffuseProduct2;
    diffuses[2]= DiffuseProduct3;
    
    vec4 speculars[3];
    speculars[0] =SpecularProduct;
    speculars[1] =SpecularProduct2;
    speculars[2] =SpecularProduct3;
    

    for(int i=0; i<=2; i++)
    {
        
        
            H = normalize( lights[i] + E );
                
            ambient += ambients[i];

            Kd = max(dot(lights[i], N), 0.0);
            diffuse += Kd*diffuses[i];
            
            Ks = pow(max(dot(N, H), 0.0), Shininess);
            specular += Ks*speculars[i];

            // discard the specular highlight if the light's behind the vertex
            if( dot(lights[i], N) < 0.0 )
            {
                specular = vec4(0.0, 0.0, 0.0, 1.0);
            }
        
    }

    //gl_FragColor = ambient + diffuse + specular;
    vec4 diffusePlusAmbient = ambient+diffuse;
 
    gl_FragColor = diffusePlusAmbient*texture2D(texture, texCoord ) +  specular;
	gl_FragColor.a = 1.0;
}