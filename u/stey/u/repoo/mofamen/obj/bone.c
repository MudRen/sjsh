//copy from bone by repoo

#include <ansi.h>
inherit ITEM;

void create()
{
  set_name(HIW"����"NOR, ({"long gu","gu"}));
  set_weight(800);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ�ѹ������Ϲ�ͷ��\n");
    set("unit", "��");
    set("material", "bone");
  }
  setup();
}
int init()
{
        add_action("do_zhengli","zhengli");
        return 1;
}
int do_zhengli()
{
        object who = this_player();
        object gujian;

        if(who->is_fighting())
           return notify_fail("��������˵��\n");
        if(who->is_busy())
           return notify_fail("����æ����!\n");
{
message_vision(WHT"\n$N������������һ�£�ֻ���׹�һ�����������ǲ��������ĺ���һ���γ�һ�ѹ���֮����\n"NOR,who);
 message("channel:rumor",YEL+"\n��"+HIB" �˲����� "NOR+YEL"��ĳ�ˣ�"+who->query("name")+"�õ�"+HIW"����"+HIM"֮��"NOR+YEL"�ˣ�\n\n"+NOR,users() );

        gujian = new("/u/repoo/mofamen/obj/gujian");
        gujian->move(who);
        destruct(this_object());
        return 1;
}
}
