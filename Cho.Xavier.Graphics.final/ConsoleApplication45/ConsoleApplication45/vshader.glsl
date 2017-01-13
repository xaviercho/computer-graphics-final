



attribute   vec4 vPosition;
attribute   vec3 vNormal;
attribute vec2 vTexCoord;



// output values that will be interpretated per-fragment
varying vec2 texCoord;
varying  vec3 fN;
varying vec3 fE;
varying  vec3 fL, fL2, fL3;

uniform mat4 ModelView;
uniform vec4 LightPosition, LightPosition2, LightPosition3;
uniform mat4 Projection;

void main()
{
    fN = vNormal;
    fE = vPosition.xyz;
    fL = LightPosition.xyz;
    fL2 = LightPosition2.xyz;
    fL3 = LightPosition3.xyz;
    
    if( LightPosition.w != 0.0 )
    {
        fL = LightPosition.xyz - vPosition.xyz;
    }
    if( LightPosition2.w != 0.0 )
    {
        fL2 = LightPosition2.xyz - vPosition.xyz;
    }
    if( LightPosition3.w != 0.0 )
    {
        fL3 = LightPosition3.xyz - vPosition.xyz;
    }

    gl_Position = Projection*ModelView*vPosition;
	texCoord    = vTexCoord;
}
