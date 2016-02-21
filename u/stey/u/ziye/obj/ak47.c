#include <ansi.h>
#include <weapon.h>
inherit THROWING;

void create()
{
        set_name("狙击步枪",({"zhuji buqiang","buqiang","qiang"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","把");
                set("base_unit", "把");
                set("material","iron");
                set("long","shoot [方向] <目标>，射程为02。\n");
                set("wield_msg", "$N很牛逼的从背上卸下一支$n端在手上。\n");
                set("unequip_msg", "$N放下了手中的$n。\n");
        }
        set_amount(1);
        init_throwing(1);

        setup();

}
void init()
{
        add_action("do_shoot","shoot");
}
int do_shoot(string str)
{
        object me,target,room;
        string dir,name;
        me=this_player();

       if(!wizardp(this_player())) return notify_fail("你看了半天，也弄不明白要怎么用，看来你太笨了！\n");
        if(!str)
        return notify_fail("shoot [方向] <名字>\n");
        if(sscanf(str,"%s %s",dir,name)==2)  {
                if(!environment(me)->query("exits/"+dir))
                return notify_fail("没有这个方向！\n");
                if(!room=find_object(environment(me)->query("exits/"+dir)))
                room=load_object(environment(me)->query("exits/"+dir));
                room=load_object(environment(me)->query("exits/"+dir));
        }
        else    {
                name=str;
                room=environment(me);
        }
                target=present(name,room);
                if(!target)     return notify_fail("那儿没有这个目标！\n");
                if(!target->is_character())     return notify_fail("那不是个生物！\n");
                tell_room(environment(me),HIY""+me->query("name")+"狞笑一声，端起手中的狙击步枪......单膝跪地，瞄着"+target->query("name")+"！\n"NOR);
                tell_room(environment(me),RED"“乒”的一声枪响，子弹朝着"+target->query("name")+"呼啸而去！\n"NOR);
                message_vision(RED"一颗子弹呼啸而来，红光闪过之后$N发出一声惨叫倒在血泊之中！\n"NOR,target);
                target->die();
                return 1;
}

