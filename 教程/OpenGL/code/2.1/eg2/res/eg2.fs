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

void main(){
	mate=u_mate;
	lt=u_lt;
	
	lt.dir=f_pos-lt_pos;
	
	fcol=lighting(t_norm,cam_pos-f_pos,mate,lt); 
}
