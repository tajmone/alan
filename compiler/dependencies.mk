adv.o: adv.c alan.h sysdep.h types.h lst.h util.h srcp.h srcp_x.h \
 lmList.h alanCommon.h token.h sym_x.h sym.h elm.h id.h acode.h \
 whr_x.h whr.h wht.h evt.h ins_x.h ins.h slt.h cnt.h cla_x.h cla.h \
 adv.h dump.h stm.h exp.h vrb.h stx.h ext.h rul.h wrd.h syn.h atr.h \
 emit.h msg.h sco.h opt.h options.h encode.h
advTest.o: advTest.c adv.c alan.h sysdep.h types.h lst.h util.h srcp.h \
 srcp_x.h lmList.h alanCommon.h token.h sym_x.h sym.h elm.h id.h \
 acode.h whr_x.h whr.h wht.h evt.h ins_x.h ins.h slt.h cnt.h cla_x.h \
 cla.h adv.h dump.h stm.h exp.h vrb.h stx.h ext.h rul.h wrd.h syn.h \
 atr.h emit.h msg.h sco.h opt.h options.h encode.h
alan.o: alan.c sysdep.h types.h util.h srcp.h alan.h lst.h \
 alan.version.h version.h srcp_x.h adv.h whr.h wht.h id.h sym.h dump.h \
 opt.h acode.h lmList.h alanCommon.h token.h pmParse.h smScan.h \
 options.h timing.h
alan.version.o: alan.version.c alan.version.h version.h
alt.o: alt.c util.h types.h srcp.h lmList.h alanCommon.h token.h \
 srcp_x.h id_x.h id.h sym.h lst.h alt.h ins.h slt.h whr.h wht.h cnt.h \
 acode.h chk.h exp.h alan.h sysdep.h evt.h stm.h elm.h emit.h dump.h
atr.o: atr.c util.h types.h srcp.h srcp_x.h id_x.h id.h sym.h adv.h \
 lst.h whr.h wht.h dump.h sysdep.h atr.h alan.h exp.h evt.h acode.h \
 elm.h emit.h ins.h slt.h cnt.h opt.h lmList.h alanCommon.h token.h \
 encode.h
chk.o: chk.c util.h types.h srcp.h options.h lst.h dump.h sysdep.h \
 exp.h alan.h wht.h id.h sym.h whr.h evt.h acode.h stm.h ins.h slt.h \
 cnt.h chk.h emit.h
cla.o: cla.c cla_x.h cla.h types.h id.h sym.h srcp.h slt.h lst.h whr.h \
 wht.h cnt.h acode.h srcp_x.h id_x.h sym_x.h elm.h emit.h util.h \
 dump.h sysdep.h lmList.h alanCommon.h token.h
claTest.o: claTest.c cla.c cla_x.h cla.h types.h id.h sym.h srcp.h \
 slt.h lst.h whr.h wht.h cnt.h acode.h srcp_x.h id_x.h sym_x.h elm.h \
 emit.h util.h dump.h sysdep.h lmList.h alanCommon.h token.h adv.h \
 ins_x.h ins.h ../interpreter/types.h ../interpreter/sysdep.h \
 ../interpreter/acode.h
cnt.o: cnt.c alan.h sysdep.h types.h lst.h srcp_x.h srcp.h lmList.h \
 alanCommon.h token.h acode.h adv.h whr.h wht.h id.h sym.h dump.h \
 stm.h ins.h slt.h cnt.h exp.h evt.h elm.h lim.h atr.h emit.h
dump.o: dump.c sysdep.h lmList.h alanCommon.h types.h token.h srcp.h
elm.o: elm.c util.h types.h srcp.h srcp_x.h id_x.h id.h sym.h lmList.h \
 alanCommon.h token.h lst.h stx.h acode.h elm.h wrd.h emit.h dump.h \
 sysdep.h
emit.o: emit.c sysdep.h types.h util.h srcp.h alan.h lst.h acode.h \
 alan.version.h version.h emit.h
encode.o: encode.c alan.h sysdep.h types.h lst.h util.h srcp.h acode.h \
 opt.h emit.h encode.h
evt.o: evt.c util.h types.h srcp.h srcp_x.h sym_x.h sym.h elm.h lst.h \
 id.h acode.h id_x.h lmList.h alanCommon.h token.h adv.h whr.h wht.h \
 dump.h sysdep.h stm.h alan.h ins.h slt.h cnt.h exp.h evt.h opt.h \
 emit.h
exp.o: exp.c util.h types.h srcp.h srcp_x.h whr_x.h whr.h wht.h id.h \
 sym.h evt.h lst.h acode.h id_x.h lmList.h alanCommon.h token.h adv.h \
 dump.h sysdep.h exp.h alan.h atr.h elm.h emit.h ins.h slt.h cnt.h \
 encode.h
ext.o: ext.c alan.h sysdep.h types.h lst.h util.h srcp.h srcp_x.h \
 sym_x.h sym.h elm.h id.h acode.h id_x.h nam.h stm.h wht.h whr.h ins.h \
 slt.h cnt.h exp.h evt.h chk.h ext.h wrd.h emit.h lmList.h \
 alanCommon.h token.h dump.h
id.o: id.c id_x.h id.h sym.h srcp.h types.h srcp_x.h elm.h lst.h \
 acode.h str.h util.h dump.h sysdep.h lmList.h alanCommon.h token.h
ins.o: ins.c ins_x.h ins.h srcp.h id.h sym.h slt.h types.h lst.h whr.h \
 wht.h cnt.h acode.h sysdep.h util.h dump.h sym_x.h elm.h id_x.h \
 srcp_x.h lmList.h alanCommon.h token.h
insTest.o: insTest.c ins.c ins_x.h ins.h srcp.h id.h sym.h slt.h \
 types.h lst.h whr.h wht.h cnt.h acode.h sysdep.h util.h dump.h \
 sym_x.h elm.h id_x.h srcp_x.h lmList.h alanCommon.h token.h
lim.o: lim.c alan.h sysdep.h types.h lst.h util.h srcp.h srcp_x.h \
 lmList.h alanCommon.h token.h adv.h whr.h wht.h id.h sym.h dump.h \
 exp.h evt.h acode.h atr.h elm.h emit.h stm.h ins.h slt.h cnt.h chk.h \
 vrb.h stx.h lim.h ext.h rul.h
lmList.o: lmList.c lmList.h alanCommon.h types.h token.h srcp.h
lst.o: lst.c lst.h util.h types.h srcp.h dump.h sysdep.h
macSpa.o: macSpa.c
main.o: main.c util.h types.h srcp.h alan.h sysdep.h lst.h spa.h \
 options.h dump.h alan.version.h version.h
msg.o: msg.c sysdep.h alan.h types.h lst.h util.h srcp.h srcp_x.h \
 lmList.h alanCommon.h token.h adv.h whr.h wht.h id.h sym.h dump.h \
 msg.h acode.h stm.h ins.h slt.h cnt.h exp.h evt.h opt.h emit.h \
 encode.h
nam.o: nam.c alan.h sysdep.h types.h lst.h util.h srcp.h srcp_x.h \
 lmList.h alanCommon.h token.h nam.h elm.h id.h sym.h acode.h str.h \
 cnt.h wht.h ext.h vrb.h ins.h slt.h whr.h stx.h msg.h dump.h emit.h
opt.o: opt.c alan.h sysdep.h types.h lst.h srcp_x.h srcp.h lmList.h \
 alanCommon.h token.h acode.h opt.h emit.h
options.o: options.c types.h dump.h sysdep.h options.h lst.h
pmErr.o: pmErr.c util.h types.h srcp.h smScan.h alanCommon.h token.h \
 sysdep.h lst.h id_x.h id.h sym.h ins_x.h ins.h slt.h whr.h wht.h \
 cnt.h acode.h cla_x.h cla.h sym_x.h elm.h lmList.h adv.h dump.h alt.h \
 atr.h alan.h exp.h evt.h emit.h chk.h ext.h lim.h msg.h opt.h res.h \
 rul.h sco.h scr.h stm.h stp.h str.h stx.h syn.h vrb.h
pmPaSema.o: pmPaSema.c util.h types.h srcp.h smScan.h alanCommon.h \
 token.h sysdep.h lst.h id_x.h id.h sym.h ins_x.h ins.h slt.h whr.h \
 wht.h cnt.h acode.h cla_x.h cla.h sym_x.h elm.h lmList.h adv.h dump.h \
 alt.h atr.h alan.h exp.h evt.h emit.h chk.h ext.h lim.h msg.h opt.h \
 res.h rul.h sco.h scr.h stm.h stp.h str.h stx.h syn.h vrb.h
pmParse.o: pmParse.c util.h types.h srcp.h smScan.h alanCommon.h \
 token.h sysdep.h lst.h id_x.h id.h sym.h ins_x.h ins.h slt.h whr.h \
 wht.h cnt.h acode.h cla_x.h cla.h sym_x.h elm.h lmList.h adv.h dump.h \
 alt.h atr.h alan.h exp.h evt.h emit.h chk.h ext.h lim.h msg.h opt.h \
 res.h rul.h sco.h scr.h stm.h stp.h str.h stx.h syn.h vrb.h pmParse.h
res.o: res.c alan.h sysdep.h types.h lst.h util.h srcp.h srcp_x.h \
 lmList.h alanCommon.h token.h res_x.h res.h id.h sym.h acode.h stx.h \
 sym_x.h elm.h id_x.h stm.h wht.h whr.h ins.h slt.h cnt.h exp.h evt.h \
 emit.h dump.h
rul.o: rul.c alan.h sysdep.h types.h lst.h util.h srcp.h srcp_x.h \
 lmList.h alanCommon.h token.h acode.h adv.h whr.h wht.h id.h sym.h \
 dump.h exp.h evt.h stm.h ins.h slt.h cnt.h rul.h emit.h
sco.o: sco.c alan.h sysdep.h types.h lst.h util.h srcp.h srcp_x.h \
 lmList.h alanCommon.h token.h adv.h whr.h wht.h id.h sym.h dump.h \
 sco.h acode.h emit.h
scr.o: scr.c alan.h sysdep.h types.h lst.h util.h srcp.h srcp_x.h \
 id_x.h id.h sym.h lmList.h alanCommon.h token.h acode.h stm.h wht.h \
 whr.h ins.h slt.h cnt.h exp.h evt.h stp.h scr.h emit.h dump.h
slt.o: slt.c slt.h types.h lst.h whr.h wht.h id.h sym.h srcp.h cnt.h \
 acode.h util.h dump.h sysdep.h
smScSema.o: smScSema.c sysdep.h types.h alan.h lst.h lmList.h \
 alanCommon.h token.h srcp.h encode.h acode.h smScan.h str.h
smScan.o: smScan.c sysdep.h types.h alan.h lst.h lmList.h alanCommon.h \
 token.h srcp.h encode.h acode.h smScan.h
smScanx.o: smScanx.c sysdep.h types.h alan.h lst.h lmList.h \
 alanCommon.h token.h srcp.h encode.h acode.h smScan.h
spa.o: spa.c spa.h
srcp.o: srcp.c alan.h sysdep.h types.h lst.h dump.h srcp_x.h srcp.h
stm.o: stm.c alan.h sysdep.h types.h lst.h util.h srcp.h srcp_x.h \
 sym_x.h sym.h elm.h id.h acode.h id_x.h whr_x.h whr.h wht.h evt.h \
 lmList.h alanCommon.h token.h adv.h dump.h exp.h atr.h emit.h stm.h \
 ins.h slt.h cnt.h scr.h sco.h opt.h encode.h
stp.o: stp.c alan.h sysdep.h types.h lst.h util.h srcp.h srcp_x.h \
 lmList.h alanCommon.h token.h exp.h wht.h id.h sym.h whr.h evt.h \
 acode.h stm.h ins.h slt.h cnt.h stp.h emit.h dump.h
str.o: str.c str.h sysdep.h types.h util.h srcp.h dump.h
stx.o: stx.c alan.h sysdep.h types.h lst.h util.h srcp.h srcp_x.h \
 id_x.h id.h sym.h sym_x.h elm.h acode.h res_x.h res.h stx.h lmList.h \
 alanCommon.h token.h adv.h whr.h wht.h dump.h wrd.h emit.h
sym.o: sym.c sym_x.h sym.h types.h elm.h srcp.h lst.h id.h acode.h \
 sysdep.h util.h lmList.h alanCommon.h token.h srcp_x.h cla_x.h cla.h \
 slt.h whr.h wht.h cnt.h
symTest.o: symTest.c sym.c sym_x.h sym.h types.h elm.h srcp.h lst.h \
 id.h acode.h sysdep.h util.h lmList.h alanCommon.h token.h srcp_x.h \
 cla_x.h cla.h slt.h whr.h wht.h cnt.h
syn.o: syn.c alan.h sysdep.h types.h lst.h util.h srcp.h srcp_x.h \
 lmList.h alanCommon.h token.h acode.h adv.h whr.h wht.h id.h sym.h \
 dump.h id_x.h syn.h wrd.h emit.h
sysdep.o: sysdep.c sysdep.h
timing.o: timing.c sysdep.h timing.h
unit.o: unit.c unitTest.h lmList.h alanCommon.h types.h token.h srcp.h \
 claTest.c cla.c cla_x.h cla.h id.h sym.h slt.h lst.h whr.h wht.h \
 cnt.h acode.h srcp_x.h id_x.h sym_x.h elm.h emit.h util.h dump.h \
 sysdep.h adv.h ins_x.h ins.h ../interpreter/types.h \
 ../interpreter/sysdep.h ../interpreter/acode.h insTest.c ins.c \
 advTest.c adv.c alan.h whr_x.h evt.h stm.h exp.h vrb.h stx.h ext.h \
 rul.h wrd.h syn.h atr.h msg.h sco.h opt.h options.h encode.h \
 symTest.c sym.c
unitList.o: unitList.c lmList.h alanCommon.h types.h token.h srcp.h
util.o: util.c util.h types.h srcp.h sysdep.h lmList.h alanCommon.h \
 token.h
vrb.o: vrb.c vrb.h srcp.h lst.h ins.h id.h sym.h slt.h types.h whr.h \
 wht.h cnt.h acode.h stx.h util.h srcp_x.h sym_x.h elm.h lmList.h \
 alanCommon.h token.h adv.h dump.h sysdep.h alt.h id_x.h emit.h
whr.o: whr.c whr_x.h whr.h wht.h id.h sym.h srcp.h evt.h lst.h acode.h \
 alan.h sysdep.h types.h util.h srcp_x.h wht_x.h sym_x.h elm.h id_x.h \
 lmList.h alanCommon.h token.h cnt.h dump.h emit.h
wht.o: wht.c alan.h sysdep.h types.h lst.h util.h srcp.h srcp_x.h \
 wht_x.h wht.h id.h sym.h id_x.h lmList.h alanCommon.h token.h emit.h \
 acode.h dump.h
wrd.o: wrd.c alan.h sysdep.h types.h lst.h util.h srcp.h srcp_x.h \
 lmList.h alanCommon.h token.h acode.h wrd.h id.h sym.h opt.h emit.h \
 dump.h
