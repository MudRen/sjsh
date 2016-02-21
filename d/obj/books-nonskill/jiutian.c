// �����ž�����֮�� by Calvin

inherit ITEM;

#include <ansi.h>

int do_kan(string arg);
void create()
{
  set_name("�����괫˵��", ({"lanling story","lanling","book"}));
  set_weight(200);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("value", 1000);
    set("no_drop", 1);
    set("long", " �����괫˵�� ���� kan �Ķ�(1-n)��\n");
    set("material", "paper");
  }
}

void init()
{
  add_action("do_kan", "kan");
}

int do_kan(string arg)
{
  object me = this_player();
  object ob = this_object();
  int size = 100;
  int nb=0;

  ob->set("value", 1000);

  if (arg == "new") return 0; 
  if (! arg || sscanf(arg, "%d", nb)!=1)
  {
    write("\n");
    me->start_more(read_file("/d/obj/books-nonskill/text/llindex"));
    write("\n");
    write ("���� kan <number> �����й��½�(1-n)��\n");
    return 1;
  }

  if ( nb <= 0 || nb > size)
    return notify_fail ("��Ҫ����һ�£�\n");

  else 
  {  
  write("\n");
  if (nb<0 && file_size("d/obj/books-nonskill/text/ll0"+nb) >= 0) 
      me->start_more(read_file("d/obj/books-nonskill/text/ll0"+nb));
  else if (file_size("d/obj/books-nonskill/text/ll"+nb) >= 0)
      me->start_more(read_file("d/obj/books-nonskill/text/ll"+nb));
  else write("��δ���룬���Ժ�");
  write("\n");
  return 1;
  }
}
