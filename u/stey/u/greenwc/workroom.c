// Room: /u/yudian/workroom.c
inherit ROOM;
void create ()
{
  set ("short", "��ѩ��");
  set ("long", @LONG

���ŭ�ţ���ѩ���졣
��������©�ġ���
�����м����һλ��Ů��
�ۣ����Ű�֥����������ǩ����
LONG);

     set("exits", ([
             "west" : __DIR__"bedroom",
             "up" : __DIR__"sleeproom",
               "east" : __DIR__"guestroom",
             "out" : __DIR__"guardroom",
         "kz" : "/d/city/kezhan",
           "wiz" : "/d/wiz/wizroom",
     ]));    
  set("outdoors", 0);
  set("valid_startroom", 1);
    set("objects", ([
        __DIR__"zhangbz" : 1,
            __DIR__"jing" : 1,
             __DIR__"banxian" : 1,
    ]));           
  setup();
}
