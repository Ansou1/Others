[BITS 64]
global strlen:function
global strncmp:function
global toupper:function
global memcpy:function

%include "strlen.s"
%include "strncmp.s"
%include "toupper.s"
%include "memcpy.s"