//Cracked by Roath

inherit ITEM;

mapping combine_list = ([
        // ������ʯ��Ƭ�ϲ���Ϊһ����ʯ
        ({ "/quest/obj/bssp_b-1",
           "/quest/obj/bssp_b-2",
           "/quest/obj/bssp_b-3" }) : "/quest/obj/�籩֮�����̱�ʯ",
]);

void create() {
        set_name("����", ({ "deposit box","box" }) );
        set_weight(100);
        set_max_encumbrance(10000);
        if( clonep() )                 set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("value", 500);
        }
      set("max_items",1);
}
int is_container() { return 1; }

void init() {
  add_action("do_put","put");
  add_action("do_combine","combine");
}

int do_put(string arg)
{
    string target, item;
    object dest, *inv,me=this_player();

    if(!arg) return 0;

    if( sscanf(arg, "%s in %s", item, target)!=4)
           return 0;

    dest = present(target, me);
    if (dest!=this_object()) return 0;

    inv = all_inventory(dest);
    if (inv && sizeof(inv)) {
       write("�������Ѿ��ж����ˡ�\n");
       return 1;
    }
    return 0;
}
