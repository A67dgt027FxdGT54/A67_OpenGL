#version 330 core
out vec4 fcol;
in vec3 tcol;
in vec2 ttex;
uniform sampler2D tex1;
uniform sampler2D tex2;
void main(){
    fcol=mix(
		texture(tex1,ttex),
		texture(tex2,vec2(-ttex.x,ttex.y)), // 将X坐标翻转即可 
		0.2
	); 
}
