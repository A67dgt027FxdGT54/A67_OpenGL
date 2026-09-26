#include"header/OpenGL.h"
using namespace std;

gl_t gl(0,800,600,"Learn OpenGL"); // 放在最前面
mesh_buf_t mb("res/ex3.ve","res/ex3.in",gle.draw_never_chg);
shader_t sd("res/ex3.vs","res/ex3.fs");
texture_t tx1("res/box.jpg",0,0);
texture_t tx2("res/face.png",1,1);

#include"header/sto.h" // 此文件中使用了 gl 对象，所以要写在它的定义之后 
void setup(){
	mb.bind();
	sd.use();
	tx1.bind();
	tx2.bind(); 
	tx1.wrap(gle.tex_clamp_to_edge,gle.tex_clamp_to_edge); 
	sd.seti("tex1",0);
	sd.seti("tex2",1);
//	gl.line(); 
}
void show(){
	if(gl.kpr(GLFW_KEY_ESCAPE)) gl.close_win();
	gl.clr_rgb(0x000000); 
	gl.triangle(0,2);
}
int main(){ 
	setup();
	gl.main_loop(); 
	return 0;
}

