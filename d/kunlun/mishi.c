//kunlun
inherit ROOM;

void create ()
{
        set ("short", "����");
        set ("long", @LONG

����������һ��ʯ�ң��˴��ܰ��������ʺ��ɼ�����������
ԭʼ����Ϊ�˰������������õ��ӽ������ڴ˽Ӵ����������
���ǡ�
LONG);

        set("exits", 
  ([ //sizeof() == 4
                "southeast" : __DIR__"dadian",
                "north" : __DIR__"houtang",
        ]));
        set("objects", ([
                __DIR__"npc/ziya" : 1,

   ]));
       setup();
	replace_program(ROOM);
}

