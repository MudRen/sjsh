inherit "/std/city.c";

void create ()
{
reload("����");
set ("short", "������");
set ("long", @LONG

����һ�����ϵĳ��С�
LONG);

  set("exits", ([
  "down" : __DIR__"jiuguan1",
  "up" : "/d/club/clubbar",
]));
  set("no_clean_up", 1);
  set("outdoor", 1);
  setup();
}

int clean_up()
{
      return 0;
}

