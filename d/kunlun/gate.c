//kunlun
#include <ansi.h>;
inherit ROOM;

void create ()
{
        set ("short", "���鶴���");
        set ("long",

"�˴������鶴��ڣ������ɾ��쳣�����˰��治Ͼ����ʫΪ֤��
�ɷ����ۣ�������ͣ�������ݣ��س���֥���������㣬����
���룻�����������Ͼպ�÷���������ӣ����潻�棻�����л���
����Χ�塣
�ſ�һ���޴�ʯ����д�ţ�
    "HIW"��    ��    ɽ    ��    ��    ��\n" NOR
 );

        set("exits", 
  ([ //sizeof() == 4
                "northup" : __DIR__"shijie",
                "southdown" : __DIR__"xiaolu",
        ]));
        set("objects", ([
                __DIR__"npc/xiao" : 2,
   ]));
        set("outdoors", "changan");
  call_other("/obj/board/kunlun_b", "???");;
       setup();
	replace_program(ROOM);
}

