//kunlun
inherit ROOM;

void create ()
{
        set ("short", "С·");
        set ("long", @LONG

        ������һƬï�ܵ����֣���ʱ�����������޵Ľ�����
ֻ������һ��С·��֪ͨ��δ���
LONG);

        set("exits", 
  ([ //sizeof() == 4
                "west" : __DIR__"xiaolu1",
                "east" : __DIR__"qilin",
        ]));
        set("objects", ([
   ]));
        set("outdoors", "changan");
       setup();
	replace_program(ROOM);
}

