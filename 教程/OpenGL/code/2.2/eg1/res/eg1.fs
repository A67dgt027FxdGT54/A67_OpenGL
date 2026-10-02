#version 330 core
#include <phong.fsh>
out vec4 fcol;

// classes
uniform material_t u_mate;
uniform light_t u_lt;
material_t mate;
light_t lt;

// arguments
in vec3 t_norm;
uniform vec3 cam_pos;
in vec3 f_pos;
uniform vec3 lt_pos;
in vec2 t_tex;

// textures
uniform sampler2D diff_tex,spec_tex; 

void main(){
	mate=u_mate;
	lt=u_lt;
	
	mate.diff=vec3(texture(diff_tex,t_tex));
	mate.spec=vec3(texture(spec_tex,t_tex));
	lt.dir=f_pos-lt_pos;
	
	fcol=lighting(t_norm,cam_pos-f_pos,mate,lt); 
}
