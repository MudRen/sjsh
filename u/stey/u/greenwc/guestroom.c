// Room: /u/yudian/workroom.c
inherit ROOM;
void create ()
{
    set ("short", "�ͷ�");
  set ("long", @LONG

����һ��ͷ�����ʰ�øɸɾ�����
�����и�����Ů��ȫ��ȫ��Ϊ���Է���
LONG);

     set("exits", ([
                "west" : __DIR__"workroom",
     ]));    
  set("outdoors", 0);
      set("objects", ([
            __DIR__"waiteress" : 1,
              __DIR__"new_jing" : 1,
    ]));           
  setup();
}
