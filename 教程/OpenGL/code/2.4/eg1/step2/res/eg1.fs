#version 330 core
#include <phong.fsh>
out vec4 fcol;

// classes
uniform material_t u_mate;
uniform light_t u_lt[6];
material_t mate;
light_t lt[6];

// arguments
in vec3 t_norm;
uniform vec3 cam_pos;
in vec3 f_pos;
uniform vec3 lt_pos[6];
in vec2 t_tex;

// textures
uniform sampler2D diff_tex,spec_tex; 

void main(){
	fcol=vec4(0.0);

	mate=u_mate;
	for(int i=0;i<6;i++) lt[i]=u_lt[i];
	
	mate.diff=vec3(texture(diff_tex,t_tex));
	mate.spec=vec3(texture(spec_tex,t_tex));
	
	for(int i=0;i<5;i++){
		if(lt[i].type!=0) lt[i].dir=f_pos-lt_pos[i];
		fcol+=lighting(t_norm,cam_pos-f_pos,mate,lt[i]); 
	}
}
