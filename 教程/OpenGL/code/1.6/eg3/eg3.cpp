#include"header/OpenGL.h"
using namespace std;

gl_t gl(0,800,600,"Learn OpenGL"); // 放在最前面
mesh_buf_t mb("res/cube.ve","res/cube.in",gle.draw_never_chg);
shader_t sd("res/eg3.vs","res/eg3.fs");
texture_t tx1("res/box.jpg",0,0);
texture_t tx2("res/face.png",1,1);
camera_t cam(0.0f,0.0f,3.0f);
timer_t tim;

#include"header/sto.h" // 此文件中使用了 gl 对象，所以要写在它的定义之后 

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
	tx1.bind();
	tx2.bind();
	sd.seti("tex1",0);
	sd.seti("tex2",1);
	gl.dept(1);
	gl.blend(0); // fix 2: disable blend
//	gl.line(); 
}
void show(){
	tim.upd();
	if(gl.kpr(GLFW_KEY_ESCAPE)) gl.close_win();
	gl.clr_rgb(0x000000); 
	trans_t tr,tri;
	tr.rot(vec3(0.5f,1.0f,0.0f),50.0f*tim.cur); 
	mat4 proj=persp(cam.fov,gl.w_div_h(),0.1f,100.0f);
	sd.setm4("view",cam.view());
	sd.setm4("proj",proj);
	for(int i=0;i<10;i++){
		tr.trans(cube_pos[i]);
		tri.rot(vec3(1.0f,0.3f,0.5f),i*20.0f);
		sd.setm4("model",tr.matr()*tri.matr());
		gl.triangle(0,12);
	}
}
int main(){ 
	setup();
	gl.main_loop(); 
	return 0;
}

