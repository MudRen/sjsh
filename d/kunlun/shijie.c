//kunlun
inherit ROOM;

void create ()
{
        set ("short", "ʯ��");
        set ("long", @LONG
һ��ʯ��С·���Ѷ��ϣ��Ĵ��紵�ݶ��������չȻ������Ĵ���
ɽ�ͣ�·�������Եÿ�һЩ�������ƽ̹��
LONG);

        set("exits", 
  ([ //sizeof() == 4
                "southdown" : __DIR__"gate",
                "westup" : __DIR__"shijie1",
        ]));
        set("objects", ([
   ]));
        set("outdoors", "changan");
       setup();
	replace_program(ROOM);
}

