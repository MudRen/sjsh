//necklace.c
#include <armor.h>
#define NULL_VALUE 0
#include <ansi.h>
inherit NECK;


void create()
{
    set_name(HBYEL "������Ȧ" NOR, ({"cody necklace", "necklace"}) );
    set_weight(2000);
    if( clonep() )
       set_default_object(__FILE__);
    else {
       set("unit", "��");
       set("long", "����һ��������ͨ�Ľ���Ȧ���ƺ���һ����ֵ���������������۾�......\nͻȻ�������ƺ��ӹ�һ˿���ײ���Ĺ�ԣ�\n���ƺ�����һ����ķ��׵�����������߻���......\n\n�㲻�ɵ�����һ��.......\n\n");
    set("material", "gold");
    set("armor_prop/armor", 7000000);
    set("no_sell",1);
    set("no_drop",1);
    set("no_get",1);
    this_object()->wear();
    }
    setup();
}
void init()
{
        object me = this_player();
        if (geteuid(me) != "cody") return;
        add_action("do_gb","gb");
        add_action("do_gift","gift");
        add_action("do_baoo","baoo");
        add_action("do_zhua","zhua");
        add_action("do_fang","fang");
}
int do_gift(string arg)
{
        int i;
        object ob,*inv;
        object me;
        inv=users();
        me = this_player();
        if( !arg )  return notify_fail("���뷢ʲô����������������ң�\n");
        if (file_size( arg ) == -1) return notify_fail("û���������\n");
                for(i=0; i<sizeof(inv); i++) 
                {
                        ob=new(arg);
                        ob->move(inv[i]);
                          tell_object(inv[i],BMAG+HIG"��!!!!!!��!!!!!!��!!!!!!��������!!!!!!!!!!!!\n\n���Ȼ�������Ϻ�����˵�ʲô��������ϸһ����ԭ����"+ob->name()+"��\n\n"NOR);
                }
                return 1;
}


int do_gb(string arg)
{
        string target, mud;
        object me, obj;
        me = this_player();
        if( !arg || arg=="" )
                return notify_fail("��Ҫ����ʲô��\n");

              shout( HBBLU +BLINK+HIM"���ٸ�ͨ�桿 "+NOR+HBBLU+HIR+ arg +"\n" NOR);
              write( HBBLU +BLINK+HIM"���ٸ�ͨ�桿 "+NOR+HBBLU+HIR+ arg +"\n" NOR);
        return 1;
}


int do_baoo(string arg)
{
        object ob, me;
        me = this_player();
if (arg!=NULL_VALUE){
    ob = LOGIN_D->find_body(arg);
    if (!ob) return notify_fail("�����Ϻ���û�����ѽ��\n");
}
        message_vision(HIC "\n$Nץס$n�����죬��$n����������\n\n"NOR,me,ob);
        ob->move(me);
        return 1;
}
int do_zhua(string arg)
{
        object ob;
        if (!arg)
        return notify_fail("��Ҫץ˭?\n");
if (arg!=NULL_VALUE){
    ob = LOGIN_D->find_body(arg);
    if (!ob) return notify_fail("�����Ϻ���û�����ѽ��\n");
}

        message_vision(HIR "\nͻȻһ�������������$N����������ֻ����$N����һ�������ĲҺ����������......��\n\n"NOR,ob);
        ob->move("/d/wiz/jail");
        message("channel:rumor", BBLU+HIR+"ֻ���������һ�����Ƶ�����ͻȻ����\n\n"+ob->query("name")+"�����ˣ�Ϊ���˼䣬�ִ������Σ��ȴ���۷��䡣\nϣ���������Ϊ�䣬����Ϊ֮��\n\n"NOR, users());
        write("Ok��\n");
        return 1;
}
int do_fang(string arg)
{
        object ob;
        if (!arg)
        return notify_fail("��Ҫ��˭?\n");
        if (arg!=NULL_VALUE){
           ob = LOGIN_D->find_body(arg);
           if (!ob) return notify_fail("�����Ϻ���û�����ѽ��\n");
        }
        ob->set_temp("block_msg/all",0);
        tell_object(ob,HIG "\n��������Ķ���˵����������ʴȣ������ط��˼䣬�Ĺ����£��������Ϊ֮���´��ٷ����������ģ���\n\n"NOR);
        ob->move("/d/city/kezhan");
        ob->set("startroom","/d/city/kezhan");
        write("Ok��\n");
        message("channel:rumor", HIG"��ҥ�ԡ�ĳ�ˣ�"+ob->query("name")+"����ʹ��ǰ�ǣ��������ˣ����ų������ˡ�\n"NOR, users());
        return 1;
}
int query_autoload()
{
        return 1;
}

void owner_is_killed()    { destruct(this_object()); }
