
/*

    The MIT License (MIT)

    Copyright (c) 2026 A67dgt027FxdGT54 (https://www.luogu.com.cn/user/1417426)

    Permission is hereby granted, free of charge, to any person obtaining a copy of
    this software and associated documentation files (the "Software"), to deal in
    the Software without restriction, including without limitation the rights to
    use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
    the Software, and to permit persons to whom the Software is furnished to do so,
    subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
    FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
    COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
    IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
    CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*/ 

#ifndef __A67_OpenGL_OpenGL_H
#define __A67_OpenGL_OpenGL_H 1
#include<bits/stdc++.h>
#include<windows.h>
#include<time.h> 
#include<conio.h>

#include "std_header.h" 

using glm::vec2;
using glm::vec3;
using glm::vec4;
using glm::mat2;
using glm::mat3;
using glm::mat4;
using glm::dot;
using glm::cross;
using glm::radians;
using glm::degrees;
using glm::ortho;
using glm::length;

mat4 persp(float fov,float aspect,float nearp,float farp){
	return glm::perspective(radians(fov),aspect,nearp,farp);
}

vec2 operator ~(vec2 _vec){
	return glm::normalize(_vec);
} 
vec3 operator ~(vec3 _vec){
	return glm::normalize(_vec);
} 
vec4 operator ~(vec4 _vec){
	return glm::normalize(_vec);
}
float operator ^(vec2 u,vec2 v){
	return glm::degrees(glm::acos(glm::dot(~u,~v)));
} 
float operator ^(vec3 u,vec3 v){
	return glm::degrees(glm::acos(glm::dot(~u,~v)));
} 
float operator ^(vec4 u,vec4 v){
	return glm::degrees(glm::acos(glm::dot(~u,~v)));
} 
std::string sdu(std::string unif,int ind){
	return unif+"["+std::to_string(ind)+"]";
}
std::string sdu(std::string unif,int ind,std::string memb){
	return unif+"["+std::to_string(ind)+"]."+memb;
}
std::string sdu(std::string unif,std::string memb){
	return unif+"."+memb;
}

struct angle_t{
	float _rad;
	angle_t(float r):_rad(r){
	}
};
using euler_t=glm::tvec3<angle_t>;
angle_t operator ""_deg (float deg){
	return angle_t{radians(deg)};
}
angle_t operator ""_rad (float rad){
	return angle_t{rad};
}
angle_t operator ""_deg (int deg){
	return angle_t{radians((float)deg)};
}
angle_t operator ""_rad (int rad){
	return angle_t{(float)rad};
}
float radians(angle_t ang){
	return ang._rad;
}
float degrees(angle_t ang){
	return degrees(ang._rad);
}
angle_t rad_to_angle(float rad){
	return angle_t{rad};
}
angle_t deg_to_angle(float deg){
	return angle_t{radians(deg)};
}
angle_t normalize(angle_t ang){ // (-180,180]
	angle_t res;
	res._rad = fmod(ang._rad,radians(360.0f));
	if(res._rad > radians(180.0f)) res._rad -= radians(360.0f);
}
angle_t operator +(angle_t x){
	return x;
}
angle_t operator -(angle_t x){
	return angle_t{-x._rad};
}
angle_t operator +(angle_t x,angle_t y){
	return angle_t{x._rad + y._rad};
}
angle_t operator -(angle_t x,angle_t y){
	return angle_t{x._rad - y._rad};
}
angle_t operator *(angle_t x,float y){
	return angle_t{x._rad*y};
}
angle_t operator *(angle_t x,int y){
	return angle_t{x._rad*(float)y};
}
angle_t operator /(angle_t x,float y){
	return angle_t{x._rad/y};
}
angle_t operator /(angle_t x,int y){
	return angle_t{x._rad/(float)y};
}
angle_t operator %(angle_t x,float y){
	return angle_t{fmod(x._rad,y)};
}
angle_t operator %(angle_t x,int y){
	return angle_t{fmod(x._rad,(float)y)};
}
bool operator ==(angle_t x,angle_t y){
	return abs(x._rad - y._rad) <= 1e-9;
}
bool operator !=(angle_t x,angle_t y){
	return !(x==y);
}
bool operator <(angle_t x,angle_t y){
	return y._rad - x._rad > 1e-9;
}
bool operator >(angle_t x,angle_t y){
	return y<x;
}
bool operator <=(angle_t x,angle_t y){
	return !(x>y);
}
bool operator >=(angle_t x,angle_t y){
	return !(x<y);
}
angle_t& operator =(angle_t& x,angle_t& y){
	x._rad=y._rad;
	return x;
}
angle_t& operator =(angle_t& x,angle_t&& y){
	x._rad=y._rad;
	return x;
}
angle_t& operator +=(angle_t& x,angle_t& y){
	x._rad+=y._rad;
	return x;
}
angle_t& operator -=(angle_t& x,angle_t& y){
	x._rad-=y._rad;
	return x;
}
angle_t& operator *=(angle_t& x,float& y){
	x=x*y;
	return x;
}
angle_t& operator *=(angle_t& x,int& y){
	x=x*y;
	return x;
}
angle_t& operator /=(angle_t& x,float& y){
	x=x/y;
	return x;
}
angle_t& operator /=(angle_t& x,int& y){
	x=x/y;
	return x;
}
angle_t& operator %=(angle_t& x,float& y){
	x=x%y;
	return x;
}
angle_t& operator %=(angle_t& x,int& y){
	x=x%y;
	return x;
}



//#include ""
//using std::cin;
//using std::cout;

void framebuffer_size_callback(GLFWwindow* _win, int _w, int _h);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset); 
void show();

void wlog(std::string level,std::string msg){
	std::ofstream _opengl_log("log/OpenGL.log",std::ios::app);
    std::time_t now = std::time(nullptr);
    char time_buf[20];
    std::strftime(time_buf, sizeof(time_buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
    _opengl_log << "[" << time_buf << "] [" <<level<<"] "<<msg<<std::endl;
}

std::string get_file(const char* _path){
	std::string code;
	std::ifstream file;
    file.exceptions(std::ifstream::failbit|std::ifstream::badbit);
	try{
		file.open(_path);
		std::stringstream stream;
		stream<<file.rdbuf();
		file.close();
		code=stream.str();
	}
	catch(std::ifstream::failure e){
        wlog("ERROR","FILE_NOT_SUCCESFULLY_READ");
        exit(-1);
	}
	return code;
}

struct _newGLenum{
	const GLenum 
		
		draw_never_chg	=GL_STATIC_DRAW,
		draw_often_chg	=GL_DYNAMIC_DRAW,
		draw_always_chg	=GL_STREAM_DRAW,
		
		tex_repeat			=GL_REPEAT,
		tex_mirrored_repeat	=GL_MIRRORED_REPEAT,
		tex_clamp_to_edge	=GL_CLAMP_TO_EDGE,
		tex_clamp_to_border	=GL_CLAMP_TO_BORDER,
		
		tex_fil_pixel	=GL_NEAREST,
		tex_fil_linear	=GL_LINEAR,
		tex_fil_ll		=GL_LINEAR_MIPMAP_LINEAR,
		tex_fil_jl		=GL_LINEAR_MIPMAP_NEAREST,
		tex_fil_lp		=GL_NEAREST_MIPMAP_LINEAR,
		tex_fil_jp		=GL_NEAREST_MIPMAP_NEAREST;
		
	
	const glm::vec3
		trans_no_scale =glm::vec3(1.0f,1.0f,1.0f),
		trans_no_trans =glm::vec3(0.0f,0.0f,0.0f);
}
gle;

#define trans_nr 0.0f,glm::vec3(1.0f,0.0f,0.0f) // deprecated

struct image_t{
	std::vector<unsigned char> data;
	int width,height,chan;
	void load_from_file(const char* path){
		stbi_set_flip_vertically_on_load(true);
		unsigned char* dat=stbi_load(img_path,&pw,&ph,&chan,0);
		if(dat) data.assign(dat,dat+pw*ph*chan);
		else wlog("ERROR","Failed to Load Texture"),exit(-1);
		stbi_image_free(dat);
	}
	void destroy(){
		width=0;
		height=0;
		chan=0;
		std::vector<unsigned char>().swap(data);
	}
};
class texture_t{ 
private:
	GLenum ms=GL_REPEAT, mt=GL_REPEAT, mr=GL_REPEAT, mn=GL_LINEAR_MIPMAP_LINEAR, mg=GL_LINEAR, mc=GL_RGB;
	bool cr=0,
		 alpha=0; /* deprecated */
	void par(){
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, ms);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, mt);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, mr);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, mn);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, mg);
	}
	unsigned int id=0;
public:
	int pw,ph,un=0,chan;
	image_t img;
	texture_t() =default;
	texture_t(const _t& other) =delete;
	texture_t& operator =(const _t& other) =delete;
	texture_t(const _t&& other){
		ms  =other.ms;
		mt  =other.mt;
		mr  =other.mr;
		mn  =other.mn;
		mg  =other.mg;
		cr  =other.cr;
		id  =other.id;
		pw  =other.pw;
		ph  =other.ph;
		un  =other.un;
		chan=other.chan;
		img =std::move(other.img);
		other.id=0;
	}
	texture_t& operator =(const _t&& other){
		if(cr&&id) glDeleteTextures(1,&id);
		ms  =other.ms;
		mt  =other.mt;
		mr  =other.mr;
		mn  =other.mn;
		mg  =other.mg;
		cr  =other.cr;
		id  =other.id;
		pw  =other.pw;
		ph  =other.ph;
		un  =other.un;
		chan=other.chan;
		img =std::move(other.img);
		other.id=0;
	}
	texture_t(const char* img_path,bool _use_alpha/* deprecated */,int _unit=0){
		un=_unit;
		img.load_from_file(img_path);
		pw=img.width;
		ph=img.height;
		chan=img.chan;
	}
	void build(const char* img_path,bool _use_alpha/* deprecated */,int _unit=0){
		un=_unit;
		img.load_from_file(img_path);
		pw=img.width;
		ph=img.height;
		chan=img.chan;
	}
	void wrap(GLenum mode_s,GLenum mode_t,GLenum mode_r=GL_REPEAT){
		if(mode_s) ms=mode_s;
		if(mode_t) mt=mode_t;
		if(mode_r) mr=mode_r;
		if(cr){
			if(!id) return;
			glActiveTexture(GL_TEXTURE0 + un);
        	glBindTexture(GL_TEXTURE_2D, id);
			par();
		}
	}
	void fil(GLenum mode_min,GLenum mode_mag){
		if(mode_min) mn=mode_min; 
		if(mode_mag) mg=mode_mag;
		if(cr){
			if(!id) return;
			glActiveTexture(GL_TEXTURE0 + un);
        	glBindTexture(GL_TEXTURE_2D, id);
			par();
		}
	}
	void create(){
		if(cr) return;
		
		glGenTextures(1, &id);
		glActiveTexture(GL_TEXTURE0 + un);
        glBindTexture(GL_TEXTURE_2D, id);
		
		par();
		
		if(chan==4) mc=GL_RGBA;
		if(chan==3) mc=GL_RGB;
		if(chan==1) mc=GL_RED;
		
		glTexImage2D(GL_TEXTURE_2D,0,mc,pw,ph,0,mc,GL_UNSIGNED_BYTE,img.data.data());
		glGenerateMipmap(GL_TEXTURE_2D);
		img.destroy();
		cr=1;
		
	}
	void bind(int unit){
		if(!cr) create();
		if(!id) return;
		glActiveTexture(GL_TEXTURE0 + unit);
		glBindTexture(GL_TEXTURE_2D, id);
	}
	void bind(){
		if(!cr) create();
		if(!id) return;
		glActiveTexture(GL_TEXTURE0 + un);
        glBindTexture(GL_TEXTURE_2D, id);
	}
	~texture_t(){if(cr&&id) glDeleteTextures(1,&id);}
}; 
void tex_border_col(float r,float g,float b,float a){
	float borderColor[] = { r, g, b, a };
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
}
void tex_border_rgb(unsigned int _rgb){tex_border_col((_rgb>>16)/255.0f,((_rgb>>8)&0xff)/255.0f,(_rgb&0xff)/255.0f,1.0f);}
void tex_border_rgba(unsigned int _rgba){tex_border_col((_rgba>>24)/255.0f,((_rgba>>16)&0xff)/255.0f,((_rgba>>8)&0xff)/255.0f,(_rgba&0xff)/255.0f);}

struct ve_t{
	std::vector<float> data;
	int mloc;
	std::vector<int> siz;
	void clr(){std::vector<float>().swap(data);}
	int calc_sum(){
		int sum=0;
		for(int i=0;i<siz.size();i++){
			sum+=siz[i];
		}
		return sum;
	}
	void append(std::vector<float> _nd){
		for(float g:_nd) data.push_back(g);
	}
}; 
struct in_t{
	std::vector<unsigned int> data;
	void clr(){std::vector<unsigned int>().swap(data);}
	void append(std::vector<unsigned int> _nd){
		for(unsigned int g:_nd) data.push_back(g);
	}
};

class mesh_buf_t {
private:
    unsigned int vao,vbo,ebo;
public:
    ve_t _ve;
	in_t _in;
    void read_vi(const char* ve_path,const char* in_path){
		std::ifstream vin(ve_path),iin(in_path);
		vin>>_ve.mloc;
		std::vector<int>().swap(_ve.siz);
		for(int _i=0,_t;_i<_ve.mloc;_i++) vin>>_t,_ve.siz.push_back(_t);
		float _tmp;
		while(vin>>_tmp) _ve.data.push_back(_tmp);
		while(iin>>_tmp) _in.data.push_back(_tmp);
	}
    void upload(GLenum _mode) { // 自动bind 
    	if(!vao) return;
        glBindVertexArray(vao);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        GLenum usage;
        if (_mode) usage=_mode;
        else usage=GL_STATIC_DRAW;
        glBufferData(GL_ARRAY_BUFFER,_ve.data.size()*4,_ve.data.data(),usage);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER,_in.data.size()*4,_in.data.data(),usage);
        GLsizei stride=0;
		GLsizeiptr offset=0; 
        for(int _i=0;_i<_ve.mloc;_i++) stride+=_ve.siz[_i]*sizeof(float);
        for (int _i=0;_i<_ve.mloc;_i++) {
		    glVertexAttribPointer(_i,_ve.siz[_i],GL_FLOAT,GL_FALSE,stride,(void*)offset);
		    glEnableVertexAttribArray(_i);
		    offset+=_ve.siz[_i]*sizeof(float);
		}
    }
    mesh_buf_t(){
    	glGenVertexArrays(1,&vao);
        glGenBuffers(1,&vbo);
        glGenBuffers(1,&ebo);
	}
	mesh_buf_t(const mesh_buf_t& other) =delete;
	mesh_buf_t& operator =(const mesh_buf_t& other) =delete;
	mesh_buf_t(const mesh_buf_t&& other){
		vao=other.vao;
		vbo=other.vbo;
		ebo=other.ebo;
		_ve=std::move(other._ve);
		_in=std::move(other._in);
		other.vao=0;
		other.vbo=0;
		other.ebo=0;
	}
	mesh_buf_t& operator =(const mesh_buf_t&& other){
		if(vao){
	        glDeleteBuffers(1,&vbo);
	        glDeleteBuffers(1,&ebo);
	        glDeleteVertexArrays(1,&vao);
		}
		vao=other.vao;
		vbo=other.vbo;
		ebo=other.ebo;
		_ve=std::move(other._ve);
		_in=std::move(other._in);
		other.vao=0;
		other.vbo=0;
		other.ebo=0;
	} 
	mesh_buf_t(const char* ve_path,const char* in_path,GLenum _upload_mode) { // 自动bind 
        glGenVertexArrays(1,&vao);
        glGenBuffers(1,&vbo);
        glGenBuffers(1,&ebo);
        read_vi(ve_path,in_path); 
        upload(_upload_mode);
    }
    mesh_buf_t(ve_t& ave,in_t& ain,GLenum _upload_mode,bool use_typ){
    	glGenVertexArrays(1,&vao);
        glGenBuffers(1,&vbo);
        glGenBuffers(1,&ebo);
        _ve=ave,_in=ain;
        upload(_upload_mode);
	}
    void bind() {
    	if(!vao) return;glBindVertexArray(vao);}
    ~mesh_buf_t() {
    	if(!vao) return;
        glDeleteBuffers(1,&vbo);
        glDeleteBuffers(1,&ebo);
        glDeleteVertexArrays(1,&vao);
    }
    void upd_ve(std::vector<float> _nve){
    	if(!vao) return;
    	glBindBuffer(GL_ARRAY_BUFFER, vbo);
    	if(_ve.data.size()) _ve.data=_nve;
        glBufferSubData(GL_ARRAY_BUFFER, 0, _nve.size() * sizeof(float), _nve.data());
	}
	void upd_in(std::vector<unsigned int> _nin) {
    	if(!vao) return;
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
        if(_in.data.size()) _in.data=_nin;
        glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, _nin.size() * sizeof(unsigned int), _nin.data());
    }
    void upd(std::vector<float> _nve,std::vector<unsigned int> _nin) {
        upd_ve(_nve);
        upd_in(_nin);
    }
    void upd_ve_t(ve_t& _nve){// !!!!!!!!!!   勿改变布局选项，下同 ！！！！！！！！！！！ 
    	if(!vao) return;
    	glBindBuffer(GL_ARRAY_BUFFER, vbo);
    	if(_ve.data.size()) _ve=_nve;
        glBufferSubData(GL_ARRAY_BUFFER, 0, _nve.data.size() * sizeof(float), _nve.data.data());
	}
	void upd_in_t(in_t& _nin) {
    	if(!vao) return;
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
        if(_in.data.size()) _in=_nin;
        glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, _nin.data.size() * sizeof(unsigned int), _nin.data.data());
    }
    void upd_t(ve_t& _nve,in_t& _nin) {
        upd_ve_t(_nve);
        upd_in_t(_nin);
    }
    void upd_ve_p(std::vector<float>& _nve,int _stt){
    	if(!vao) return;
    	size_t stride=_ve.calc_sum();
    	size_t offs=_stt*stride*sizeof(float);
    	size_t _siz=_nve.size()*sizeof(float);
    	glBindBuffer(GL_ARRAY_BUFFER,vbo);
    	glBufferSubData(GL_ARRAY_BUFFER,offs,_siz,_nve.data());
    	if(!_ve.data.empty())
    		std::copy(_nve.begin(),_nve.end(),_ve.data.begin()+_stt*stride);
	} 
	void upd_in_p(std::vector<unsigned int>& _nin,int _stt){
    	if(!vao) return;
    	size_t offs=_stt*3*sizeof(unsigned int);
    	size_t _siz=_nin.size()*sizeof(unsigned int);
    	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,ebo);
    	glBufferSubData(GL_ELEMENT_ARRAY_BUFFER,offs,_siz,_nin.data());
    	if(!_in.data.empty())
    		std::copy(_nin.begin(),_nin.end(),_in.data.begin()+_stt*3);
	} 
    void clr(){_ve.clr();_in.clr();}
};

struct light_t{
	vec3 dir=vec3(0.0f,0.0f,-1.0f)/*0*/;
	vec3 spot_dir=vec3(0.0f,0.0f,-1.0f)/*2*/;
	vec3 amb=vec3(1.0f,1.0f,1.0f),diff=vec3(1.0f,1.0f,1.0f),spec=vec3(1.0f,1.0f,1.0f);
	float kc=1.0f,kl=0.09f,kq=0.032f;/*att*/
	bool use_angle=0;
	float icutoff=12.5f,ocutoff=17.5f;/*2*/
	angle_t icutoff_ang=12.5_deg,ocutoff_ang=17.5_deg;
	int type;
};
class shader_t{
private:
	std::unordered_map<std::string,bool> oncepath;
	std::string get_include_path(std::string& code,int& i,std::string cur_path=""){
		while(code[++i]==' ');
		bool stddir;
		std::string path;
		if(code[i]=='<') stddir=1;
		else if(code[i]=='\"') stddir=0;
		i++;
		while(
			(stddir && code[i]!='>')||
			(!stddir && code[i]!='\"')
		){
			path+=code[i++];
		}
		i++;
		if(stddir) path="sd_lib/"+path;
		else{
			int path_head=0;
			while(path.substr(path_head,3)=="../") {
				int path_end=cur_path.length();
				if(path_end==0) break;
				path_head+=3;
				path_end--;
				while((path_end)&&cur_path[--path_end]!='/');
				if(path_end) path_end++;
				cur_path=cur_path.substr(0,path_end);
			}
			path=cur_path+path.substr(path_head);
		}
		return path;
	}
	std::string sd_pre(std::string code,std::string ccur_path=""){
		std::string result;
		int nmstt=0,nmend=0;
		for(int i=0;i<code.length();i++){
			if(code[i]=='#'){ // #    include < 
				nmend=i;
				std::string opername;
				while(code[++i]==' ');
				while(
					('0'<=code[i] && code[i]<='9')||
					('A'<=code[i] && code[i]<='Z')||
					('a'<=code[i] && code[i]<='z')
				) opername+=code[i++];
				if(opername=="include"){
					std::string include_path=get_include_path(code,i,ccur_path);
					std::string new_code,pre_new_code;
					if(oncepath[include_path]) {
						pre_new_code="";
					}
					else{
						oncepath[include_path]=1;
						new_code=get_file(include_path.c_str());
						int path_end=include_path.length();
						while(path_end&&include_path[--path_end]!='/');
						if(path_end) path_end++;
						pre_new_code="\n"+sd_pre(new_code,include_path.substr(0,path_end))+"\n";
					} 
					result+= code.substr(nmstt,nmend-nmstt)
							+pre_new_code;
					nmstt=i;
				}
			}
		}
		result+=code.substr(nmstt);
		return result;
	}
	unsigned int vs,fs,sp;
public:
	shader_t (){}
	~shader_t(){
		if(!sp) return;
		glDeleteProgram(sp); 
	}
	shader_t(const shader_t& other)=delete;
	shader_t& operator =(const shader_t& other) =delete;
	shader_t(const shader_t&& other){
		if(!other.sp) return;
		oncepath=std::move(other.oncepath);
		sp      =other.sp;
		other.sp=0;
	}
	shader_t& operator =(const shader_t&& other){
		if(!other.sp) return;
		oncepath=std::move(other.oncepath);
		sp      =other.sp;
		other.sp=0;
	}
	shader_t(const char* vs_path,const char* fs_path){
		std::string svscode=get_file(vs_path),
					sfscode=get_file(fs_path);
		svscode=sd_pre(svscode);
		sfscode=sd_pre(sfscode);
	    const char* vscode = svscode.c_str();
	    const char* fscode = sfscode.c_str();
	    /*********************************
		 *
		 *               Compile and Link Shader
		 */
		vs = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vs, 1, &vscode, NULL);
		glCompileShader(vs);
		int success;
		char infoLog[512];
		glGetShaderiv(vs, GL_COMPILE_STATUS, &success);
		if(!success){
		    glGetShaderInfoLog(vs, 512, NULL, infoLog);
		    wlog("ERROR",std::string("Vertex Shader Compile Error: ")+infoLog);
		    exit(-1);
		}
		fs = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fs, 1, &fscode, NULL);
		glCompileShader(fs);
		glGetShaderiv(fs, GL_COMPILE_STATUS, &success);
		if(!success){
		    glGetShaderInfoLog(fs, 512, NULL, infoLog);
		    wlog("ERROR",std::string("Fragment Shader Compile Error: ")+infoLog);
		    exit(-1);
		}
		sp = glCreateProgram();
		glAttachShader(sp, vs);
		glAttachShader(sp, fs);
		glLinkProgram(sp);
		glGetProgramiv(sp, GL_LINK_STATUS, &success);
		if(!success) {
		    glGetProgramInfoLog(sp, 512, NULL, infoLog);
			wlog("ERROR",std::string("Shader Program Link Error: ")+infoLog);
		    exit(-1);
		}
		glDeleteShader(vs);
		glDeleteShader(fs);
	}
	void use(){
		if(!sp) return;glUseProgram(sp);}
	void setb	(const std::string &name, bool value) {
		if(!sp) return;
		glUniform1i(glGetUniformLocation(sp, name.c_str()), (int)value);
	}
	void seti	(const std::string &name, int value){
		if(!sp) return;
		glUniform1i(glGetUniformLocation(sp, name.c_str()), value);
	}
	void setf	(const std::string &name, float value){
		if(!sp) return;
		glUniform1f(glGetUniformLocation(sp, name.c_str()), value);
	}
	void set2f	(const std::string &name, float v1,float v2){
		if(!sp) return;
		glUniform2f(glGetUniformLocation(sp, name.c_str()), v1,v2);
	}
	void set2f  (const std::string &name, glm::vec2 vec){
		if(!sp) return;
		glUniform2f(glGetUniformLocation(sp, name.c_str()), vec.x,vec.y);
	}
	void set3f	(const std::string &name, float v1,float v2,float v3){
		if(!sp) return;
		glUniform3f(glGetUniformLocation(sp, name.c_str()), v1,v2,v3);
	}
	void set3f	(const std::string &name, glm::vec3 vec){
		if(!sp) return;
		glUniform3f(glGetUniformLocation(sp, name.c_str()), vec.x,vec.y,vec.z);
	}
	void set4f	(const std::string &name, float v1,float v2,float v3,float v4){
		if(!sp) return;
		glUniform4f(glGetUniformLocation(sp, name.c_str()), v1,v2,v3,v4);
	}
	void set4f	(const std::string &name, glm::vec4 vec){
		if(!sp) return;
		glUniform4f(glGetUniformLocation(sp, name.c_str()), vec.x,vec.y,vec.z,vec.w);
	}
	void setm3	(const std::string &name, glm::mat3 _matr){
		if(!sp) return;
		glUniformMatrix3fv(glGetUniformLocation(sp, name.c_str()), 1, GL_FALSE, glm::value_ptr(_matr));
	}
	void setm4	(const std::string &name, glm::mat4 _matr){
		if(!sp) return;
		glUniformMatrix4fv(glGetUniformLocation(sp, name.c_str()), 1, GL_FALSE, glm::value_ptr(_matr));
	}
	void setlight(const std::string &name,light_t lt){
		seti(name+".type",lt.type);
		set3f(name+".dir",lt.dir);
		set3f(name+".spot_dir",lt.spot_dir);
		set3f(name+".amb",lt.amb);
		set3f(name+".diff",lt.diff);
		set3f(name+".spec",lt.spec);
		setf(name+".kc",lt.kc);
		setf(name+".kl",lt.kl);
		setf(name+".kq",lt.kq);
		if(lt.use_angle){
			setf(name+".icutoff",degrees(lt.icutoff_ang));
			setf(name+".ocutoff",degrees(lt.ocutoff_ang));
		}
		else{
			setf(name+".icutoff",lt.icutoff);
			setf(name+".ocutoff",lt.ocutoff);
		}
	} 
	void setlight_array(const std::string &name,int index,light_t lt){
		setlight(name+"["+std::to_string(index)+"]",lt);
	}
};

void glfw_error_callback(int _error, const char* _desc) { // GLFW 错误回调：当GLFW出现错误时调用此函数
    wlog("ERROR","GLFW ERROR "+std::to_string(_error)+": "+_desc);// 日志输出错误码
}

class timer_t{
private:
	std::map<int,std::pair<float,std::function<void()> > > itvms;
	int tot=0;
public:
	float abso=0.0f,las=0.0f,dis=0.0f,cur=0.0f,offs=0.0f;
	float fps=60;int curf=0;
	timer_t(){} 
	timer_t(int _fps):fps(_fps){}
	void upd(){
		las=cur;
		abso=glfwGetTime();
		cur=abso-offs;
		dis=cur-las;
		
		for(auto& g:itvms){
			float d=g.second.first;
			auto itvm=g.second.second;
			if(floor(cur/d)-floor(las/d)>=0.99f) itvm();
		}
	}
	void clear(){
		offs=abso;
		cur=0.0f,dis=0.0f,las=0.0f;
	}
	void fslp(){
//		int slp=int(1000.0f/fps - dis*1000.0f);
//		if(slp>0)Sleep(slp);
//		curf++;
		float tgt=1.0f/fps*(++curf);
		int slp=int(1000.0f*(tgt-abso));
		if(slp>0)Sleep(slp);
	}
	float get_fps(){
		return 1.0f/dis;
	}
	void add_itvm(int id,float d,std::function<void()> itvm){ // intervalometer
		itvms[id]=std::make_pair(d,itvm);
	}
	void del_itvm(int id){
		itvms.erase(id);
	}
	void clr_itvm(){
		itvms.clear();
	}
};

class gl_t{
private:
	bool _edep,_eblend,_ecf;
	std::map<int,bool> _kdn; 
public:
	int winw,winh;
	GLFWwindow* window;
	~gl_t(){glfwTerminate();}// 释放GLFW使用的资源；退出时调用
	void close_win(){glfwSetWindowShouldClose(window, true);}
	void clr_col(float _r,float _g,float _b,float _a){
		glClearColor(_r,_g,_b,_a);
		glClear(
			GL_COLOR_BUFFER_BIT | 
			(_edep ? GL_DEPTH_BUFFER_BIT : 0 ) 
		);
	}
	void clr_rgb(unsigned int _rgb){clr_col((_rgb>>16)/255.0f,((_rgb>>8)&0xff)/255.0f,(_rgb&0xff)/255.0f,1.0f);}
	void clr_rgba(unsigned int _rgba){clr_col((_rgba>>24)/255.0f,((_rgba>>16)&0xff)/255.0f,((_rgba>>8)&0xff)/255.0f,(_rgba&0xff)/255.0f);}
	void set_win(int _ww,int _wh){winw=_ww;winh=_wh;} 
	void main_loop(){ // 用户自行bind 
		// 11. Call framebuffer_size_callback
		framebuffer_size_callback(nullptr,winw,winh);
		while(!glfwWindowShouldClose(window)){
			show();
		    glfwSwapBuffers(window);
		    glfwPollEvents();
		}
	}
	bool kpr(int key){
		if('a'<=key&&key<='z') key-=32;
		if(key>7) return glfwGetKey(window,key)==GLFW_PRESS;
		else return glfwGetMouseButton(window,key)==GLFW_PRESS;
	}
	bool kprf(int key){
		if(kpr(key)){
			if(!_kdn[key]){
				_kdn[key]=1;
				return 1;
			}
		}
		else _kdn[key]=0;
		return 0;
	}
	void line(){glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);}
	void fill(){glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);}
	// 初始化，创建窗口
	//       使用OpenGL 3.3，窗口宽高标题
	gl_t(bool _use_v3_3,int _ww,int _wh,const char* _wtitle){
		winw=_ww;
		winh=_wh;
		
		// 1.设置错误回调函数
		glfwSetErrorCallback(glfw_error_callback);

		// 2.初始化GLFW
		if (!glfwInit()) {
		    wlog("ERROR","GLFW init error");
		    exit(-1);
		}

		// 3.版本及核心模式设定；此设置可能导致部分旧设备上运行出错
 		if(_use_v3_3) {
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	    }

		// 4.创建窗口
		window = glfwCreateWindow(_ww, _wh,_wtitle, NULL, NULL);
		if (window == NULL){
		    wlog("ERROR","Failed to create GLFW window");
		    exit(-1);
		}
		glfwMakeContextCurrent(window);

		// 5.设置窗口大小回调
		glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

		// 6.初始化GLAD
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
		    wlog("ERROR","Failed to initialize GLAD");
		    exit(-1);
		}
		 
		// 7.默认允许混合
		blend(true);
		
		
		// 8.设置顶点缓冲对象(VBO)和顶点数组对象(VAO)
//		setup();
		
//		wlog("CORRECT","Use VAO,VBO&EBO Correct");
		
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
		
//		// 9.深度测试
//		if(_u3d=_use_3d)glEnable(GL_DEPTH_TEST); 
//		
//		// 10.鼠标设置
//	    if(_use_mouse)glfwSetCursorPosCallback(window, mouse_callback),glfwSetScrollCallback(window, scroll_callback); 
		
	}
	void triangle(int _stt,int _siz){glDrawElements(GL_TRIANGLES, _siz*3, GL_UNSIGNED_INT, (void*)(uintptr_t)(_stt*3*4));}
	float w_div_h(){return (float)(winw)/(float)(winh);}
	bool dept(bool enable){
		_edep=enable;
		if(enable) glEnable(GL_DEPTH_TEST);
		else glDisable(GL_DEPTH_TEST);
	}
	bool blend(bool enable){
		_eblend=enable;
		if(enable) {
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
		}
		else glDisable(GL_BLEND);
	}
	bool cull_face(bool enable){
		_ecf=enable;
		if(enable)
		 glEnable(GL_CULL_FACE);
		else
		 glDisable(GL_CULL_FACE);
	}
	bool mouse_cb(){
		glfwSetCursorPosCallback(window, mouse_callback);
		glfwSetScrollCallback(window, scroll_callback); 
	}
	bool mouse(){
		glfwSetCursorPosCallback(window, mouse_callback);
		glfwSetScrollCallback(window, scroll_callback); 
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	}
	
	gl_t() =delete;
	gl_t(const gl_t& other) =delete;
	gl_t& operator =(const gl_t& other) =delete;
	gl_t(const gl_t&& other) =delete;
	gl_t& operator =(const gl_t&& other) =delete;
};

#if 0
class actor{
private:
	texture_t _tex;
	mesh_buf_t _mb;
	shader_t _sd;
public:
	actor(){}
	actor(texture_t _tex_arg,mesh_buf_t _mb_arg,shader_t _sd_arg){
		_tex=*_tex_ptr;
	}
}; 
#endif

glm::mat4 transd(glm::vec3 _scale_x,float _rotate_deg,glm::vec3 _rotate_axis,glm::vec3 _translate){ // deprecated
	glm::mat4 _trans;
	_trans = glm::translate(_trans,_translate);
	_trans = glm::rotate(_trans, glm::radians(_rotate_deg), _rotate_axis);
	_trans = glm::scale(_trans, _scale_x);
	return _trans;
}
glm::mat4 transr(glm::vec3 _scale_x,float _rotate_rad,glm::vec3 _rotate_axis,glm::vec3 _translate){ // deprecated
	glm::mat4 _trans;
	_trans = glm::translate(_trans,_translate);
	_trans = glm::rotate(_trans, _rotate_rad, _rotate_axis);
	_trans = glm::scale(_trans, _scale_x);
	return _trans;
}

void norma(float& ang){ // (-180,180]
	ang=fmod(ang,360.0f);
	if(ang>180.0f) ang-=360.0f;
}
class camera_t{
public:
	vec3 pos=vec3(0,0,0);
	float mov_spd=2.5f,sensit=0.1f,fov=45.0f;
	float cplim=89.0f;
	bool keepy=0; 
private:
	vec3 front=vec3(0,0,-1),world_up=vec3(0,1,0),right,up;
	float yaw=-90.0f,pitch=0.0f,roll=0.0f;
	void checkp(bool cp){
		if(cp){
            if(pitch>cplim) pitch=cplim;
            if(pitch<-cplim) pitch=-cplim;
        }
	}
	vec3 hord(vec3 dir){
		if(!keepy) return dir;
		dir.y=0.0f;
		if(length(dir)==0) return vec3(0.0f);
		return ~dir;
	}
	
public:
	void upd(){
        front = glm::normalize(vec3(
        	cos(glm::radians(yaw)) * cos(glm::radians(pitch)),
        	sin(glm::radians(pitch)),
        	sin(glm::radians(yaw)) * cos(glm::radians(pitch))
		));
        right = glm::normalize(glm::cross(front, world_up)); 
        up    = glm::normalize(glm::cross(right, front));
        
        mat4 rot=glm::rotate(mat4(1.0f),radians(roll),front);
        vec4 up4=rot*vec4(up.x,up.y,up.z,1.0f);
        vec4 rt4=rot*vec4(right.x,right.y,right.z,1.0f);
        up= ~vec3(up4.x,up4.y,up4.z);
        right= ~vec3(rt4.x,rt4.y,rt4.z);
	}
	
	camera_t(){}
	camera_t(vec3 _pos,float _yaw=-90.0f,float _pitch=0.0f,float _roll=0.0f){
		pos=_pos;
		yaw=_yaw;
		pitch=_pitch;
		roll=_roll;
		norma(   yaw   );norma(  pitch    );norma(roll);
		upd();
	}
	camera_t(vec3 _pos, angle_t _yaw=-90.0_deg, angle_t _pitch=0.0_deg, angle_t _roll=0.0_deg)
		:camera_t(_pos, degrees(_yaw), degrees(_pitch), degrees(_roll)){
		}
	camera_t(float posX,float posY,float posZ,float _yaw=-90.0f,float _pitch=0.0f,float _roll=0.0f){
		pos=vec3(posX,posY,posZ);
		yaw=_yaw;
		pitch=_pitch;
		roll=_roll;
		norma(   yaw   );norma(  pitch    );norma(roll);
		upd();
	}
	camera_t(float posX,float posY,float posZ, angle_t _yaw=-90.0_deg, angle_t _pitch=0.0_deg, angle_t _roll=0.0_deg)
		:camera_t(posX, posY, posZ, degrees(_yaw), degrees(_pitch), degrees(_roll)){
		}
	void set_yaw(float _yaw){yaw=_yaw;norma(  yaw    );upd();}
	void set_yaw(angle_t _yaw){yaw=degrees(_yaw);norma(  yaw    );upd();}
	void set_pitch(float _pitch,GLboolean cp=true){
		pitch=_pitch;
		checkp(cp);
		norma(   pitch   );
		upd();
	}
	void set_pitch(angle_t _pitch,GLboolean cp=true){
		pitch=degrees(_pitch);
		checkp(cp);
		norma(   pitch   );
		upd();
	}
	void set_roll(float _roll){roll=_roll;norma(   roll   );upd();}
	void set_roll(angle_t _roll){roll=degrees(_roll);norma(   roll   );upd();}
	
	float get_yaw(){return yaw;}
	float get_pitch(){return pitch;}
	float get_roll(){return roll;}
	angle_t get_yaw_angle(){return deg_to_angle(yaw);}
	angle_t get_pitch_angle(){return deg_to_angle(pitch);}
	angle_t get_roll_angle(){return deg_to_angle(roll);}
	vec3 get_front(){return front;}
	vec3 get_right(){return right;}
	vec3 get_up(){return up;}
	
	void move(vec3 _offset){pos+=_offset;upd();}
	void movef(float dt){pos+=hord(front)*mov_spd*dt;}
	void mover(float dt){pos+=hord(right)*mov_spd*dt;}
	void moveu(float dt){pos+=vec3(0.0f,1.0f,0.0f)*mov_spd*dt;}
	
	glm::mat4 view(){
		return glm::lookAt(pos,pos+front,up);
	}
	void set_look(float _yaw,float _pitch){
		yaw=_yaw;norma(   yaw   );
		set_pitch(_pitch);
	}
	void set_look(angle_t _yaw,angle_t _pitch){
		yaw=degrees(_yaw);norma(   yaw   );
		set_pitch(degrees(_pitch));
	}
	void mov_look(float xoffset,float yoffset,GLboolean cp=true){
		yaw+=xoffset*sensit,
		pitch+=yoffset*sensit;
		norma(   yaw   );
		checkp(cp);norma(  pitch    );
        upd();
	}
	void mov_look(glm::vec2 _offset,GLboolean cp=true){
		yaw+=_offset.x*sensit,
		pitch+=_offset.y*sensit;
		norma(   yaw   );
		checkp(cp);norma(  pitch    );
        upd();
	}
	void scl_look(float yoffset,float minfov=1.0f,float maxfov=45.0f){
		if(minfov>maxfov) std::swap(minfov,maxfov);
		fov-=yoffset;
		if(fov<minfov)fov=minfov;
        if(fov>maxfov)fov=maxfov;
	}
}; 

//#if 0 
void operator *=(glm::vec4& _vec,glm::mat4 _trans){
	_vec = _trans * _vec;
}
//#endif 

struct mousectrl_t{
	float lastX=0, lastY=0, nowX=0,nowY=0; 
	bool firstMouse=1;
	void set(float _x,float _y) {lastX=nowX,lastY=nowY;nowX=_x,nowY=_y;}
	float offx(){return nowX-lastX;}
	float offy(){return lastY-nowY;}
	glm::vec2 offs(){return glm::vec2(nowX-lastX,lastY-nowY);}
	void init(float xpos,float ypos){
		if(firstMouse){set(xpos,ypos);set(xpos,ypos);firstMouse=false;}
	}
}; 

struct trans_t{
private:
	vec3 mtrans=vec3(0.0f,0.0f,0.0f),
		 mrota =vec3(1.0f,0.0f,0.0f),
		 mscale =vec3(1.0f,1.0f,1.0f);
	angle_t mrot=0_deg;
	euler_t mrote=euler(0_deg,0_deg,0_deg);
	std::string mrots="YXZ";
public:
	bool use_eul=0;
	bool use_angle=0;
	bool rad=0;
	void trans(vec3 _trans){
		mtrans=_trans;
	}
	void rot(vec3 _axis,float _angle){
		mrota=_axis;
		if(rad) mrot=rad_to_angle(_angle);
		else    mrot=deg_to_angle(_angle);
		use_eul=0;
	}
	void rot(vec3 _axis,angle_t ang){
		mrota=_axis;
		mrot=ang;
		use_eul=0;
	}
	void rote(vec3 _euler,std::string _rots="YXZ"){
		if(rad) mrote=euler_t(
			rad_to_angle(_euler.x), 
			rad_to_angle(_euler.y), 
			rad_to_angle(_euler.z)
		);
		else    mrote=euler_t(
			deg_to_angle(_euler.x), 
			deg_to_angle(_euler.y), 
			deg_to_angle(_euler.z)
		);
		use_eul=1;
		mrots=_rots;
	}
	void rote(euler_t ae,std::string as="YXZ"){
		mrote=ae;
		use_eul=1;
		mrots=as;
	}
	void scale(vec3 _scale){
		mscale=_scale;
	}
	void scale(float _scale){
		mscale=vec3(_scale,_scale,_scale);
	}
	mat4 matr() const{
		glm::mat4 _trans;
		_trans=glm::translate(_trans,mtrans);
		if(use_eul){
			for(int i=mrots.length()-1;i>=0;i--){
				switch (mrots[i]){
					case 'X': case 'x': 
						_trans=glm::rotate(
							_trans,
							radians(mrote.x),
							vec3(1.0f,0.0f,0.0f)
						); 
						break;
					case 'Y': case 'y': 
						_trans=glm::rotate(
							_trans,
							radians(mrote.y),
							vec3(0.0f,1.0f,0.0f)
						); 
						break;
					case 'Z': case 'z': 
						_trans=glm::rotate(
							_trans,
							radians(mrote.z),
							vec3(0.0f,0.0f,1.0f)
						); 
						break;
				}
			}
		}
		else _trans=glm::rotate(_trans,radians(mrot),mrota);
		_trans=glm::scale(_trans,mscale);
		return _trans;
	}
	mat3 norm_matr(){
		return mat3(glm::transpose(glm::inverse(matr())));
	}
};



#endif // __A67_OpenGL_OpenGL_H
