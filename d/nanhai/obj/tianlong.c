// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */

#include <weapon.h>

inherit F_UNIQUE;
//inherit HALBERD;

void create()
{
        set_name("�����", ({ "tianlong ji", "halberd" ,"ji"}));
        set("long", @LONG
����һ��������ͭ�ƣ�����д�š��������ơ��ĸ�С�֡�?
LONG);
        set("weight", 100);

        if(clonep())
        set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 20);
     //set("replace_file", "/d/obj/weapon/halberd/huaji");
                //set("material", "blacksteel");
        }
       // init_halberd(90);
       // set("is_monitored",1);
        setup();
}

