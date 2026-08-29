//float amb_s=0.1;
//float spec_s=0.5;
//int shininess=32;

struct material_t{
	vec3 diff;
	vec3 spec;
	float shini;
};
struct light_t{
	vec3 dir,spot_dir;
	vec3 amb,diff,spec;
	float kc,kl,kq;
	float icutoff,ocutoff;
	int type;// 0-directional 1-point 2-spotlight -1-invalid
};

vec4 lighting(vec3 norm,vec3 v_dir,material_t materi,light_t lt){
	if(lt.type==-1) return vec4(0.0f,0.0f,0.0f,0.0f);
	norm=normalize(norm);
	float dis=length(lt.dir);
	lt.dir=normalize(-lt.dir);
	v_dir=normalize(v_dir);
	lt.icutoff=cos(radians(lt.icutoff));
	lt.ocutoff=cos(radians(lt.ocutoff));
	
	float att=1.0;
	if(lt.type==1||lt.type==2){ // point
		att=1.0/(lt.kc+lt.kl*dis+lt.kq*dis*dis);
	}
	vec3 refd=reflect(-lt.dir,norm);
	vec3 amb=lt.amb*materi.diff;
	float inten=1.0;
	if(lt.type==2) {
		float theta=dot(lt.dir,normalize(-lt.spot_dir));
		float epsilon=lt.icutoff-lt.ocutoff;
		inten=clamp((theta-lt.ocutoff)/epsilon,0.0,1.0);
	}
	vec3 diff=lt.diff*(max(dot(norm,lt.dir),0.0)*materi.diff);
	vec3 spec=lt.spec*(pow(max(dot(v_dir,refd),0.0),materi.shini)*materi.spec);
	diff*=inten;
	spec*=inten;
	vec3 res=amb+diff+spec;
	res*=att;
	return vec4(res,1.0);
}
