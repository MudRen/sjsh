#include <ansi.h>
#include <weapon.h> 
#include <dbase.h>
inherit SWORD;
 void create()
  {
     set_name(HIW"�ٺ�"NOR, ({ "bai he" ,"flower","hua" }) );
     set_weight(100);
     set("long","һ����׵İٺ�,һ�����ڽ��ʱ���õģ������Ű���Ϻá�\n");
     set("value", 0);
     set("material", "flower");
     set("no_drop", "��Ư�������Űɡ�\n");
     set("unit", "��");
     set("wield_msg", "$N�����ó�һ��$n���������С�\n");
     set("unequip_msg", "$N����İ�$n���������ϡ�\n");
     set("weapon_prop/armor", 1); 
     set("weapon_prop/per", 20);     set("weapon_prop/personality", 5);
     setup();
  }

