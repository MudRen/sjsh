#include <ansi.h>
inherit NPC;
void create()
{ set_name(HIG"����"NOR,({"plava", "xiao yiq"}));
  set("long","���۵��Ϲ����ࡣ\n");
  set("title",HIM"�۶���ֿ��"NOR);
  set("gender","����");
  set("per",40);
  set("age",20);
  set("str",35);
  set("con",30);
  set("int",30);
  set("max_kee", 1000);
  set("eff_kee", 1000);
  set("kee", 1000);
  set("max_force",2000);
  set("force",400);
  set("combat_exp", 1000000);
    set("inquiry",([
       "yiq": "��������ң����۶����Ϲ���С�۶��İְ�����\n",
       "����": "��������ң����۶����Ϲ���С�۶��İְ�����\n",
       "rainy": "���������Ű���Я���۶����֣����ű���������죬������һ������ֵ�ʱ��\n",
       "����": "���������Ű���Я���۶����֣����ű���������죬������һ������ֵ�ʱ��\n",
       "�۶�": "���������Ű���Я���۶����֣����ű���������죬������һ������ֵ�ʱ��\n",
        ]));

  set("chat_chance",8);
  set("chat_msg", ({
  HIG"��������������:�۶����ǿ����������ҽ����������ã�������������Ŀ������ã�\n"NOR,
  HIG"��������˼����:�۶���û�����������ˣ�\n"NOR,

          }));

  setup();
  carry_object("/u/yiq/obj/zuanjie")->wear();
}
