#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
set_name(WHT "���Ǻ��⽣" NOR,({"iceword","icy"}));
  set_weight(1);
   if(clonep())
       set_default_object(__FILE__);
   else{
               set("unit", "��");
                set("value", 1);
                set("rigidity", 10);
                set("sharpness", 10);
                set("unique", 1);
                set("no_give",1);
                set("no_get",1);
                set("material", "steel");
                set("weapon_prop/dodge", 50);
                set("weapon_prop/parry", 50);
                set("treasure",1);
                set("wield_neili", 300);
                set("wield_maxneili", 700);
                set("wield_str", 22);
         set("long","һ�Ѿ�Ө��͸����ǧ�꺮�����ɵĽ������������Ķ࿴һ��Ҳ������ܲ��ˡ�\n");
         set("wield_msg", "��Ȼ���ܳ���һ������һ�ѽ�׵�"WHT"���Ǻ��⽣"NOR"������$N���С�\n"  );
         set("unwield_msg","$N�����ذ����е�"WHT"���Ǻ��⽣"NOR"��ϴ��һ�飬Ȼ����һ�ӣ�����ʧ�ڿ����С�\n" );
         set("unequip_msg","�������ذ����е�"WHT"���Ǻ��⽣"NOR"��ϴ��һ�飬Ȼ����һ�ӣ��ѽ��ջ��ڽ�ϻ�\n" );
       }
   init_sword(200);
   setup();
}

