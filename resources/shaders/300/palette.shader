#version 130

uniform sampler2D texture0;
varying vec2 texcoord;

#if COMPILING_VERTEX_PROGRAM
    void vert(){
        gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
        gl_FrontColor = gl_Color;
        texcoord = gl_MultiTexCoord0.st;
    }
#elif COMPILING_FRAGMENT_PROGRAM
    void frag(){
        gl_FragColor = vec4(gl_Color.rgb, texture(texture0, texcoord).a);
    }
#endif
