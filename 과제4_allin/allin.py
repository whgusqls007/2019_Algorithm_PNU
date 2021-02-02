i,o=open("allin.inp"),open("allin.out","w");F=i.readline;N,l,h,a,b,c,d,e=int(F()),int(F()),0,1,0,0,0,0
for j in range(2,N+1):
 t=int(F())
 if t>h:h,b=t,j
 if e<=h-l:e,d,c=h-l,b,a
 if t<=l:l,h,a=t,t,j
o.write("%s %s"%(c,d))