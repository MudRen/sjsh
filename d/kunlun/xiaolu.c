//kunlun
inherit ROOM;

void create ()
{
        set ("short", "С·");
        set ("long", @LONG

        �ۿ��Ѿ�����С·�ľ�ͷ�ˣ�����æ�ӿ���
������
LONG);

        set("exits", 
  ([ //sizeof() == 4
                "northup" : __DIR__"gate",
                "east" : __DIR__"xiaolu1",
        ]));
        set("objects", ([
   ]));
        set("outdoors", "changan");
       setup();
	replace_program(ROOM);
}

