inherit ROOM;
void create ()
{
  set ("short", "�ʼһ�԰");
  set ("long", @LONG

�����԰�������˼��ɾ���
LONG);

     set("exits", ([
             "enter" : __DIR__"workroom",
     ]));    
  set("outdoors", 1);
    set("objects", ([        
         "/d/obj/flower/flower.c" : 5,
       "/d/dntg/hgs/npc/gardener.c" : 1,
    ]));
  setup();
}
