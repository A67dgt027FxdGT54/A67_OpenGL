#include"header/OpenGL.h"
using namespace std;

gl_t gl(0,800,600,"Learn OpenGL"); // 放在最前面
mesh_buf_t mb("res/cube_normal.ve","res/cube.in",gle.draw_never_chg),
		   lt_mb("res/cube.ve","res/cube.in",gle.draw_never_chg);
shader_t lt_sd("res/eg1l.vs","res/eg1l.fs"),
		 sd("res/eg1.vs","res/eg1.fs");
texture_t diff_tx("res/container2.png",1,0),
		  spec_tx("res/spec.png",1,1);
camera_t cam(0.0f,0.0f,3.0f);
timer_t tim;
mousectrl_t g_mouse;

#include"header/sto.h" // 此文件中使用了 gl 对象，所以要写在它的定义之后 

vec3 lt_pos[]={
	vec3(0.7f,0.2f,2.0f),
	vec3(2.3f,-3.3f,-4.0f),
	vec3(-4.0f,2.0f,-12.0f),
	vec3(0.0f,0.0f,-3.0f)
};
vec3 cube_pos[] = {
	vec3( 0.0f,  0.0f,  0.0f), 
	vec3( 2.0f,  5.0f, -15.0f), 
	vec3(-1.5f, -2.2f, -2.5f),  
	vec3(-3.8f, -2.0f, -12.3f),  
	vec3( 2.4f, -0.4f, -3.5f),  
	vec3(-1.7f,  3.0f, -7.5f),  
	vec3( 1.3f, -2.0f, -2.5f),  
	vec3( 1.5f,  2.0f, -2.5f), 
	vec3( 1.5f,  0.2f, -1.5f), 
	vec3(-1.3f,  1.0f, -1.5f)  
};
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
	
	//     Directional
	lt.type=0;
	lt.amb=vec3(0.2f,0.2f,0.2f); // dark   white / gray
	lt.diff=vec3(0.5f,0.5f,0.5f);// mid    white / gray
	lt.spec=vec3(1.0f,1.0f,1.0f);// bright white
	lt.dir=vec3(-0.2f,-1.0f,-0.3f); // type 0
	sd.setlight("u_lt[0]",lt);
	// or sd.setlight_array("u_lt",0,lt);
	
	//     Point
	lt.kc=1.0f;lt.kl=0.09f;lt.kq=0.032f;
	for(int i=1;i<=4;i++){
		lt.type=1;
		sd.setlight_array("u_lt",i,lt);
		// or sd.set_light(sdu("u_lt",i),lt);
		sd.set3f(sdu("lt_pos",i),lt_pos[i-1]);
	}
	
	// others
	sd.set3f("cam_pos",cam.pos);
	
	// draw object
	sd.setm4("view",cam.view());
	sd.setm4("proj",proj);
	trans_t obj_tr;
	for(int i=0;i<10;i++){
	    obj_tr.trans(cube_pos[i]);
	    obj_tr.rot(vec3(1.0f,0.3f,0.5f),i*20.0f);
	    sd.setm4("model",obj_tr.matr());
	    sd.setm3("m_norm",obj_tr.norm_matr());
	    gl.triangle(0,12);
	}
	
	// draw light
	lt_mb.bind();
	lt_sd.use();
	trans_t tr;
	tr.scale(0.2f);
	lt_sd.setm4("view",cam.view());
	lt_sd.setm4("proj",proj);
	for(int i=0;i<4;i++){
		tr.trans(lt_pos[i]);
		lt_sd.setm4("model",tr.matr());
		gl.triangle(0,12);
	}
}
int main(){ 
	setup();
	gl.main_loop(); 
	return 0;
}

