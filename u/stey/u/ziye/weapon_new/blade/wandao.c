// by snowcat 10/15/1997
// blade.c
//add keenness by ziye 2001/3

#include <weapon.h>

inherit BLADE;

string *names = ({
  "���䵶",
  "���䵶",
  "�����䵶",
});

string *ids = ({
  "chang wan dao",
  "duan wan dao",
  "yueya wan dao",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i],({ ids[i], "wan dao", "blade" }) );
  set_weight(2000);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("long", "һ�������ս����\n");
    set("unit", "��");
    set("value", 400);
    set("material","metal");
       set("keenness", 10);
  }
  init_blade(25);
  setup();
}

