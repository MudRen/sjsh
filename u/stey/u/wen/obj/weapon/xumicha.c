// xumicha.c
//weiwei

#include <weapon.h>

inherit FORK;

void create()
{
        set_name("���ֲ�", ({ "xumi cha", "cha","fork" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 500000);
                set("material", "iron");
                set("long", "�������ڽ���֮����ת����������֮�񣬶˵�һ�����������\n");
                set("wield_msg", "$N����һ��$n����ʱ����֮����������Ұ��\n");
				 set("unwield_msg", "$N�������е�$n�����ֶ��գ���Χ���˷·�о����˵�ʲô��\n");
        }
        init_fork(125);
        setup();
}

