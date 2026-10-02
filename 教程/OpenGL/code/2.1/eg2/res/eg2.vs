#version 330 core
layout (location = 0) in vec3 v_pos;
layout (location = 1) in vec3 v_norm;
uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;
uniform mat3 m_norm;
out vec3 t_norm;
out vec3 f_pos;
void main(){
	t_norm=m_norm*v_norm;
    gl_Position=proj*view*model*vec4(v_pos.x,v_pos.y,v_pos.z,1.0);
    f_pos=vec3(model*vec4(v_pos.x,v_pos.y,v_pos.z,1.0));
}
