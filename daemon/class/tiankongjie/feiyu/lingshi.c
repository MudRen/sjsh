// peaceful
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        extra = me->query_skill("feiyu");
        if((int) me->query_skill("feiyu",1) < 120)
                return notify_fail("��Ŀ�����ë�ļ�����û����,�����ܲ�����¥��������");
//      if( !target ) target = offensive_target(me);
//      if( !target
//      ||      !target->is_character()
//      ||      !me->is_fighting(target) )
//              return notify_fail("����Ӱҹ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if((string)me->query("family/family_name")!="��ս�")
                return notify_fail("��������ս粻��֮�أ��㲻���ã�\n");
        if(me->query("env/invisibility"))
                return notify_fail("���Ѿ��׳��������ˡ�\n");
        if((int)me->query("max_force") < 1000 )
                return notify_fail("������������Բ���������\n");
        if(me->query("force") < 600)
                return notify_fail("�������������\n");
        me->add("force",-100);
message_vision( HIC "$N�������գ�һ������ɫ����ë�������е�������������������ȥ�ˡ�\n\n" NOR,me,target);
        me->set("env/invisibility",1);
        me->start_busy(1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), extra/3);
        return 1;
}
void remove_effect(object me)
{
        me->delete("env/invisibility");
        tell_object(me, "$N�����������̣������������ɻ�$N���������˲����ˡ�\n");
}

