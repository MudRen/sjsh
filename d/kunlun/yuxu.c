//kunlun
inherit ROOM;

void create ()
{
        set ("short", "���鹬");
        set ("long", @LONG

�������鹬�ˣ���ǰһλ�����������붨������
���������˳�����˵�ͷ��
LONG);

        set("exits", 
  ([ //sizeof() == 4
                "south" : __DIR__"hundun",

        ]));
        set("objects", ([
                __DIR__"npc/tianzun" : 1,
                __DIR__"npc/tongzi" : 1,


   ]));
       setup();
	replace_program(ROOM);
}

