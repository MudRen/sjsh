//kunlun
inherit ROOM;

void create ()
{
        set ("short", "ʯ��");
        set ("long", @LONG
    ʯ����ǰ����������ԼԼ�ѿɿ���ɽ����ϼ���������Ƿ���
ɽ������ʱ�Ӵ��������о���������
LONG);

        set("exits", 
  ([ //sizeof() == 4
                "eastdown" : __DIR__"shijie",
                "north" : __DIR__"lingyun",
        ]));
        set("objects", ([
   ]));
        set("outdoors", "changan");
       setup();
	replace_program(ROOM);
}

