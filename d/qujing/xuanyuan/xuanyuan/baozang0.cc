inherit ROOM;

void create ()
{
  set ("short", "��Ĺ����");
  set ("long", @LONG
�ƽ𣬰��������飬��解�ҹ���顭��
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"baozang",
  "south" : __DIR__"maze12",
]));  
  set("objects", ([
  ]));
  setup();
}

void init()
{
    object gold,book;
    gold = new ("/obj/money/gold");
//    gold->set_amount(500);
  //  gold->move("/d/xuanyuan/baozang0");             
    book= new("/d/obj/book/needlebook");
    book->move("/d/xuanyuan/baozang0");
}                                                                                         
