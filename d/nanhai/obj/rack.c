// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
inherit ITEM;

void create()
{
        set_name("������", ({ "rack" }) );
        set_weight(500000);
        set_max_encumbrance(40000);
        if( clonep() ) {
                object a,b,c,d,e;
                 seteuid(getuid());
                if(d=new("/d/obj/weapon/hammer/hammer"))
                  d->move(this_object());

                  seteuid(getuid());
     if(b=new("/d/obj/weapon/sword/changjian"))
       b->move(this_object());

                set_default_object(__FILE__);
        } else {
                set("unit", "��");
                set("long", "����һ��Ѱ���ļ��ӣ����������ѷ�һЩ���\n");
                set("value", 0);
        }
}

int is_container() { return 1; }

