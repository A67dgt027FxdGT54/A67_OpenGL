#include"header/OpenGL.h"
using namespace std;

gl_t gl(0,800,600,"Learn OpenGL"); // 放在最前面
mesh_buf_t mb("res/eg2.ve","res/eg2.in",gle.draw_never_chg);
shader_t sd("res/eg2.vs","res/eg2.fs");
texture_t tx1("res/box.jpg",0,0);
texture_t tx2("res/face.png",1,1);

#include"header/sto.h" // 此文件中使用了 gl 对象，所以要写在它的定义之后 
void setup(){
	mb.bind();
	sd.use();
	tx1.bind();
	tx2.bind();
	sd.seti("tex1",0);
	sd.seti("tex2",1);
//	gl.line(); 
}
void show(){
	if(gl.kpr(GLFW_KEY_ESCAPE)) gl.close_win();
	gl.clr_rgb(0x000000); 
	trans_t tr;
	tr.scale(0.5f); // or tr.scale(vec3(0.5f,0.5f,0.5f));
	tr.rot(vec3(0.0f,0.0f,1.0f),90.0f); // or tr.rote(vec3(0.0f,0.0f,90.0f));
	sd.setm4("tr",tr.matr());
	gl.triangle(0,2);
}
int main(){ 
	setup();
	gl.main_loop(); 
	return 0;
}

