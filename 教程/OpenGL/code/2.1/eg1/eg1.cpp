#include"header/OpenGL.h"
using namespace std;

gl_t gl(0,800,600,"Learn OpenGL"); // 放在最前面
mesh_buf_t mb("res/cube.ve","res/cube.in",gle.draw_never_chg),
		   lt_mb("res/cube.ve","res/cube.in",gle.draw_never_chg);
shader_t lt_sd("res/eg1l.vs","res/eg1l.fs"),
		 sd("res/eg1.vs","res/eg1.fs");
camera_t cam(0.0f,0.0f,3.0f);
timer_t tim;
mousectrl_t g_mouse;

#include"header/sto.h" // 此文件中使用了 gl 对象，所以要写在它的定义之后 

vec3 lt_pos(1.2f,1.0f,2.0f);
void setup(){
	mb.bind();
	sd.use();
	gl.dept(1);
	gl.blend(0); // fix 2: disable blend
	gl.mouse();
//	gl.line(); 
}
void show(){
	tim.upd();
	if(gl.kpr(GLFW_KEY_ESCAPE)) gl.close_win();
	if(gl.kpr('W')) cam.movef(tim.dis);
	if(gl.kpr('A')) cam.mover(-tim.dis);
	if(gl.kpr('S')) cam.movef(-tim.dis);
	if(gl.kpr('D')) cam.mover(tim.dis);
	if(gl.kpr(' ')) cam.moveu(tim.dis); // press space to fly higher
	if(gl.kpr(GLFW_KEY_LEFT_SHIFT)) cam.moveu(-tim.dis); // press shift to fly lower
	gl.clr_rgb(0x000000); 
	mat4 proj=persp(cam.fov,gl.w_div_h(),0.1f,100.0f);
	
	// bind object
	mb.bind();
	sd.use();
	
	// draw object
	sd.setm4("model",mat4(1.0f)); // not any trans
	sd.setm4("view",cam.view());
	sd.setm4("proj",proj);
	gl.triangle(0,12);
	
	// bind light
	lt_mb.bind();
	lt_sd.use();
	
	// draw light
	trans_t tr;
	tr.trans(lt_pos); // move to the position
	tr.scale(0.2f); // scale to be smaller
	lt_sd.setm4("model",tr.matr());
	lt_sd.setm4("view",cam.view());
	lt_sd.setm4("proj",proj);
	gl.triangle(0,12);
}
int main(){ 
	setup();
	gl.main_loop(); 
	return 0;
}

