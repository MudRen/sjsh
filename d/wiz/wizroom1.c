//��ʦ������
//by Calvin

inherit ROOM;

void create ()
{
        set ("short", "��ʦ������");
        set ("long", @LONG
�� ��ʦָ��
[��������]:cd,more,ls,rm,cat,edit,mv,rmdir,cp,mkdir,tail
[�������]:call,dest,localcmds,update,clone,ilist
[��ѯָ��]:config,mudlist,cost,whoami,ff,info,qload,mem,status,where,pwd,ulist
[ϵͳ����]:dump,profile,purge,shutdown,callouts,chinese,cleanup,possess
[ϵͳ����]:rehash,reclaim,reboot,promote,wizlock,edemote,snoop
[����]:goto,halt,summon,smash

�� ��ʦ��������
1.immortal <anything>       �趨�Լ���Ϊ����֮����״̬�ﵽ���Ի�����ʱ��ֵ
2.invisibility <number>     �趨���εĳ̶ȡ� 0 - 10
3.msg_home <anything>       �趨���Լ��� home �ؼ�ʱ��ʾ��ѶϢ��
4.msg_min <anything>        �趨��ʹ�� goto ����ĳ��ʱ, ������������ѶϢ��
5.msg_mout <anything>       �趨��ʹ�� goto �뿪ʱ, ԭ�������������������ѶϢ��
6.msg_clone <anything>      �趨�� clone NPC �� OBJ ʱ����ʾ��ѶϢ��
7.msg_dest <anything>       �趨�� dest NPC �� OBJ ʱ����ʾ��ѶϢ��������� OBJ
7.msg_dest <anything>       �Ǵ�����Լ�����ʱ�򲻻���ѶϢ��
LONG);

        set("exits", 
        ([ //sizeof() == 4
      "down" : __DIR__"wizroom",
        ]));

        set("objects", ([
                "/adm/object/bm" : 1,
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
