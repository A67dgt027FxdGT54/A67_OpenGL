#include"header/OpenGL.h"
using namespace std;

gl_t gl(0,800,600,"Learn OpenGL"); // 放在最前面
mesh_buf_t mb("res/cube_normal.ve","res/cube.in",gle.draw_never_chg),
		   lt_mb("res/cube.ve","res/cube.in",gle.draw_never_chg);
shader_t lt_sd("res/eg2l.vs","res/eg2l.fs"),
		 sd("res/eg2.vs","res/eg2.fs");
texture_t diff_tx("res/container2.png",1,0),
		  spec_tx("res/spec.png",1,1);
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
	diff_tx.bind();
	spec_tx.bind();
//	gl.line(); 
}
void show(){
	tim.upd();
	if(gl.kpr(GLFW_KEY_ESCAPE)) gl.close_win();
	if(gl.kpr('W')) cam.movef(tim.dis);
	if(gl.kpr('A')) cam.mover(-tim.dis);
	if(gl.kpr('S')) cam.movef(-tim.dis);
	if(gl.kpr('D')) cam.mover(tim.dis);
	if(gl.kpr(' ')) cam.moveu(tim.dis);
	if(gl.kpr(GLFW_KEY_LEFT_SHIFT)) cam.moveu(-tim.dis);
	gl.clr_rgb(0x000000); 
	mat4 proj=persp(cam.fov,gl.w_div_h(),0.1f,100.0f);
	
	mb.bind();
	sd.use();
	
	// set mate
	sd.seti("diff_tex",0);
	sd.seti("spec_tex",1);
	sd.setf("u_mate.shini", 32.0f);
	
	// set light
	light_t lt;
	lt.type=2;
	lt.amb=vec3(0.2f,0.2f,0.2f); // dark   white / gray
	lt.diff=vec3(0.5f,0.5f,0.5f);// mid    white / gray
	lt.spec=vec3(1.0f,1.0f,1.0f);// bright white
	lt.kc=1.0f;
	lt.kl=0.09f;
	lt.kq=0.032f;
	lt.spot_dir=cam.get_front();
	lt.icutoff=12.5f;
	lt.ocutoff=17.5f;
	sd.setlight("u_lt",lt);
	sd.set3f("lt_pos",cam.pos);
	
	// others
	sd.set3f("cam_pos",cam.pos);
	
	// draw object
	sd.setm4("model",mat4(1.0f));
	sd.setm4("view",cam.view());
	sd.setm4("proj",proj);
	sd.setm3("m_norm",mat3(1.0f));
	gl.triangle(0,12);
	
	// draw light
	lt_mb.bind();
	lt_sd.use();
	trans_t tr;
	tr.trans(lt_pos);
	tr.scale(0.2f);
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

