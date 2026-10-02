#version 330 core
out vec4 fcol;
in vec2 ttex;
uniform sampler2D tex1;
uniform sampler2D tex2;
void main(){
	fcol=mix(
		texture(tex1,ttex),
		texture(tex2,ttex),
		0.2
	); 
//	fcol=vec4( // fix 1: Set Alpha to 1.0f
//		vec3(
//			mix(
//				texture(tex1,ttex),
//				texture(tex2,ttex),
//				0.2
//			)
//		),
//		1.0f
//	);
}
