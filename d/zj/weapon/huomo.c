// ��ħǹ by Calvin

#include <ansi.h>
#include <weapon.h>
inherit SPEAR;
void create()
{
           set_name(HIR "��ħǹ" NOR, ({"huomo spear", "huomo","qiang","spear"}));
           set_weight(1500);
           if( clonep() )
           set_default_object(__FILE__);
        else {
           set("long","һ֧ȫ��ͨ�����Ǹճ�¯��Ϊ���͵ı���,�����Ͼ��Ļ��������\n");
           set("unit", "֧");
           set("replace_file", "/d/obj/weapon/spear/tieqiang");
           set("value", 10000);
           set("no_sell", 1);
           set("wield_msg", "$Nͷ��һ����Ʒ���,���������ȴ�����һ��ȫ��ͨ��������\n");
           set("unwield_msg", "һ����������,$N���е�$n����һ˿������ӳ��������ʧ�ˡ�\n");
           set("weapon_prop/strength", 10);
                   }
           init_spear(100);
           set("is_monitored",1);
           setup();
}
