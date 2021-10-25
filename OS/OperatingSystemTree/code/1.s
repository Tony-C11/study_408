
a.out:     file format elf64-x86-64


Disassembly of section .init:

0000000000001000 <_init>:
    1000:	f3 0f 1e fa          	endbr64 
    1004:	48 83 ec 08          	sub    $0x8,%rsp
    1008:	48 8b 05 d9 2f 00 00 	mov    0x2fd9(%rip),%rax        # 3fe8 <__gmon_start__>
    100f:	48 85 c0             	test   %rax,%rax
    1012:	74 02                	je     1016 <_init+0x16>
    1014:	ff d0                	call   *%rax
    1016:	48 83 c4 08          	add    $0x8,%rsp
    101a:	c3                   	ret    

Disassembly of section .plt:

0000000000001020 <putchar@plt-0x10>:
    1020:	ff 35 e2 2f 00 00    	push   0x2fe2(%rip)        # 4008 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	ff 25 e4 2f 00 00    	jmp    *0x2fe4(%rip)        # 4010 <_GLOBAL_OFFSET_TABLE_+0x10>
    102c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000001030 <putchar@plt>:
    1030:	ff 25 e2 2f 00 00    	jmp    *0x2fe2(%rip)        # 4018 <putchar@GLIBC_2.2.5>
    1036:	68 00 00 00 00       	push   $0x0
    103b:	e9 e0 ff ff ff       	jmp    1020 <_init+0x20>

0000000000001040 <wait@plt>:
    1040:	ff 25 da 2f 00 00    	jmp    *0x2fda(%rip)        # 4020 <wait@GLIBC_2.2.5>
    1046:	68 01 00 00 00       	push   $0x1
    104b:	e9 d0 ff ff ff       	jmp    1020 <_init+0x20>

0000000000001050 <fork@plt>:
    1050:	ff 25 d2 2f 00 00    	jmp    *0x2fd2(%rip)        # 4028 <fork@GLIBC_2.2.5>
    1056:	68 02 00 00 00       	push   $0x2
    105b:	e9 c0 ff ff ff       	jmp    1020 <_init+0x20>

Disassembly of section .text:

0000000000001060 <_start>:
    1060:	f3 0f 1e fa          	endbr64 
    1064:	31 ed                	xor    %ebp,%ebp
    1066:	49 89 d1             	mov    %rdx,%r9
    1069:	5e                   	pop    %rsi
    106a:	48 89 e2             	mov    %rsp,%rdx
    106d:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    1071:	50                   	push   %rax
    1072:	54                   	push   %rsp
    1073:	4c 8d 05 96 01 00 00 	lea    0x196(%rip),%r8        # 1210 <__libc_csu_fini>
    107a:	48 8d 0d 1f 01 00 00 	lea    0x11f(%rip),%rcx        # 11a0 <__libc_csu_init>
    1081:	48 8d 3d d1 00 00 00 	lea    0xd1(%rip),%rdi        # 1159 <main>
    1088:	ff 15 52 2f 00 00    	call   *0x2f52(%rip)        # 3fe0 <__libc_start_main@GLIBC_2.2.5>
    108e:	f4                   	hlt    
    108f:	90                   	nop

0000000000001090 <deregister_tm_clones>:
    1090:	48 8d 3d a9 2f 00 00 	lea    0x2fa9(%rip),%rdi        # 4040 <__TMC_END__>
    1097:	48 8d 05 a2 2f 00 00 	lea    0x2fa2(%rip),%rax        # 4040 <__TMC_END__>
    109e:	48 39 f8             	cmp    %rdi,%rax
    10a1:	74 15                	je     10b8 <deregister_tm_clones+0x28>
    10a3:	48 8b 05 2e 2f 00 00 	mov    0x2f2e(%rip),%rax        # 3fd8 <_ITM_deregisterTMCloneTable>
    10aa:	48 85 c0             	test   %rax,%rax
    10ad:	74 09                	je     10b8 <deregister_tm_clones+0x28>
    10af:	ff e0                	jmp    *%rax
    10b1:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    10b8:	c3                   	ret    
    10b9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000010c0 <register_tm_clones>:
    10c0:	48 8d 3d 79 2f 00 00 	lea    0x2f79(%rip),%rdi        # 4040 <__TMC_END__>
    10c7:	48 8d 35 72 2f 00 00 	lea    0x2f72(%rip),%rsi        # 4040 <__TMC_END__>
    10ce:	48 29 fe             	sub    %rdi,%rsi
    10d1:	48 89 f0             	mov    %rsi,%rax
    10d4:	48 c1 ee 3f          	shr    $0x3f,%rsi
    10d8:	48 c1 f8 03          	sar    $0x3,%rax
    10dc:	48 01 c6             	add    %rax,%rsi
    10df:	48 d1 fe             	sar    %rsi
    10e2:	74 14                	je     10f8 <register_tm_clones+0x38>
    10e4:	48 8b 05 05 2f 00 00 	mov    0x2f05(%rip),%rax        # 3ff0 <_ITM_registerTMCloneTable>
    10eb:	48 85 c0             	test   %rax,%rax
    10ee:	74 08                	je     10f8 <register_tm_clones+0x38>
    10f0:	ff e0                	jmp    *%rax
    10f2:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    10f8:	c3                   	ret    
    10f9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001100 <__do_global_dtors_aux>:
    1100:	f3 0f 1e fa          	endbr64 
    1104:	80 3d 35 2f 00 00 00 	cmpb   $0x0,0x2f35(%rip)        # 4040 <__TMC_END__>
    110b:	75 33                	jne    1140 <__do_global_dtors_aux+0x40>
    110d:	55                   	push   %rbp
    110e:	48 83 3d e2 2e 00 00 	cmpq   $0x0,0x2ee2(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    1115:	00 
    1116:	48 89 e5             	mov    %rsp,%rbp
    1119:	74 0d                	je     1128 <__do_global_dtors_aux+0x28>
    111b:	48 8b 3d 16 2f 00 00 	mov    0x2f16(%rip),%rdi        # 4038 <__dso_handle>
    1122:	ff 15 d0 2e 00 00    	call   *0x2ed0(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    1128:	e8 63 ff ff ff       	call   1090 <deregister_tm_clones>
    112d:	c6 05 0c 2f 00 00 01 	movb   $0x1,0x2f0c(%rip)        # 4040 <__TMC_END__>
    1134:	5d                   	pop    %rbp
    1135:	c3                   	ret    
    1136:	66 2e 0f 1f 84 00 00 	cs nopw 0x0(%rax,%rax,1)
    113d:	00 00 00 
    1140:	c3                   	ret    
    1141:	66 66 2e 0f 1f 84 00 	data16 cs nopw 0x0(%rax,%rax,1)
    1148:	00 00 00 00 
    114c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000001150 <frame_dummy>:
    1150:	f3 0f 1e fa          	endbr64 
    1154:	e9 67 ff ff ff       	jmp    10c0 <register_tm_clones>

0000000000001159 <main>:
    1159:	55                   	push   %rbp
    115a:	48 89 e5             	mov    %rsp,%rbp
    115d:	e8 ee fe ff ff       	call   1050 <fork@plt>
    1162:	85 c0                	test   %eax,%eax
    1164:	75 0c                	jne    1172 <main+0x19>
    1166:	bf 41 00 00 00       	mov    $0x41,%edi
    116b:	e8 c0 fe ff ff       	call   1030 <putchar@plt>
    1170:	eb f4                	jmp    1166 <main+0xd>
    1172:	e8 d9 fe ff ff       	call   1050 <fork@plt>
    1177:	85 c0                	test   %eax,%eax
    1179:	75 0c                	jne    1187 <main+0x2e>
    117b:	bf 42 00 00 00       	mov    $0x42,%edi
    1180:	e8 ab fe ff ff       	call   1030 <putchar@plt>
    1185:	eb f4                	jmp    117b <main+0x22>
    1187:	b8 00 00 00 00       	mov    $0x0,%eax
    118c:	e8 af fe ff ff       	call   1040 <wait@plt>
    1191:	b8 00 00 00 00       	mov    $0x0,%eax
    1196:	5d                   	pop    %rbp
    1197:	c3                   	ret    
    1198:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
    119f:	00 

00000000000011a0 <__libc_csu_init>:
    11a0:	f3 0f 1e fa          	endbr64 
    11a4:	41 57                	push   %r15
    11a6:	4c 8d 3d 3b 2c 00 00 	lea    0x2c3b(%rip),%r15        # 3de8 <__frame_dummy_init_array_entry>
    11ad:	41 56                	push   %r14
    11af:	49 89 d6             	mov    %rdx,%r14
    11b2:	41 55                	push   %r13
    11b4:	49 89 f5             	mov    %rsi,%r13
    11b7:	41 54                	push   %r12
    11b9:	41 89 fc             	mov    %edi,%r12d
    11bc:	55                   	push   %rbp
    11bd:	48 8d 2d 2c 2c 00 00 	lea    0x2c2c(%rip),%rbp        # 3df0 <__do_global_dtors_aux_fini_array_entry>
    11c4:	53                   	push   %rbx
    11c5:	4c 29 fd             	sub    %r15,%rbp
    11c8:	48 83 ec 08          	sub    $0x8,%rsp
    11cc:	e8 2f fe ff ff       	call   1000 <_init>
    11d1:	48 c1 fd 03          	sar    $0x3,%rbp
    11d5:	74 1f                	je     11f6 <__libc_csu_init+0x56>
    11d7:	31 db                	xor    %ebx,%ebx
    11d9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    11e0:	4c 89 f2             	mov    %r14,%rdx
    11e3:	4c 89 ee             	mov    %r13,%rsi
    11e6:	44 89 e7             	mov    %r12d,%edi
    11e9:	41 ff 14 df          	call   *(%r15,%rbx,8)
    11ed:	48 83 c3 01          	add    $0x1,%rbx
    11f1:	48 39 dd             	cmp    %rbx,%rbp
    11f4:	75 ea                	jne    11e0 <__libc_csu_init+0x40>
    11f6:	48 83 c4 08          	add    $0x8,%rsp
    11fa:	5b                   	pop    %rbx
    11fb:	5d                   	pop    %rbp
    11fc:	41 5c                	pop    %r12
    11fe:	41 5d                	pop    %r13
    1200:	41 5e                	pop    %r14
    1202:	41 5f                	pop    %r15
    1204:	c3                   	ret    
    1205:	66 66 2e 0f 1f 84 00 	data16 cs nopw 0x0(%rax,%rax,1)
    120c:	00 00 00 00 

0000000000001210 <__libc_csu_fini>:
    1210:	f3 0f 1e fa          	endbr64 
    1214:	c3                   	ret    

Disassembly of section .fini:

0000000000001218 <_fini>:
    1218:	f3 0f 1e fa          	endbr64 
    121c:	48 83 ec 08          	sub    $0x8,%rsp
    1220:	48 83 c4 08          	add    $0x8,%rsp
    1224:	c3                   	ret    
