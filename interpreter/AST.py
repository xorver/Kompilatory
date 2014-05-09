
class Node(object):
    #def __str__(self):
    #    return self.printTree()
    def accept(self, visitor):
        return getattr(visitor, 'visit_'+self.__class__.__name__)(self)
    def acceptInt(self, visitor):
        return visitor.visit(self)
    def setLineNo(line):
        self.line=line


class Program(Node):
    def __init__(self, declarations, fundefs, instructions):
        self.declarations=declarations
        self.fundefs=fundefs
        self.instructions=instructions
    
class Declarations(Node):
    def __init__(self):
        self.list=[]
		
class Declaration(Node):
	def __init__(self,type,inits):
		self.type=type
		self.inits=inits

class Inits(Node):
	def __init__(self):
		self.list=[]
		
class Init(Node):
    def __init__(self,id,expression):
        self.id=id
        self.expression=expression

class Instructions(Node):
	def __init__(self):
		self.list=[]
        
class ParExpr(Node):
    def __init__(self,expression):
        self.expression=expression
        self.line=expression.line

class BinExpr(Node):
    def __init__(self,first,operator,second):
        self.first=first
        self.operator=operator
        self.second=second
        self.line=first.line

class ExprList(Node):
    def __init__(self):
        self.list=[]


class FunDefs(Node):
	def __init__(self):
		self.list=[]
		
class FunExpr(Node):
    def __init__(self,id,expressionList):
        self.id=id
        self.expressionList=expressionList
        self.line=id.line
    

class FunDef(Node):
    def __init__(self,type,id,argList,compoundInstr):
        self.type=type
        self.id=id
        self.argList=argList
        self.compoundInstr=compoundInstr

class ArgList(Node):
	def __init__(self):
		self.list=[]
		
class Arg(Node):
    def __init__(self,type,id):
        self.type=type
        self.id=id

class PrintInstr(Node):
    def __init__(self,expression):
        self.expression=expression

class LabeledInstr(Node):
    def __init__(self,id,instruction):
        self.id=id
        self.instruction=instruction
        
class Assignment(Node):
    def __init__(self,id,expression):
        self.id=id
        self.expression=expression

class CompoundInstr(Node):
    def __init__(self,declarations,instructions):
        self.declarations=declarations
        self.instructions=instructions
        
class Condition(Node):
    def __init__(self,expression):
        self.expression=expression        
        
class ChoiceInstr(Node):
    def __init__(self,condition,instruction,elseInstruction):
        self.condition=condition
        self.instruction=instruction
        self.elseInstruction=elseInstruction       

class Break(Node):
	def __init__(self):
		pass
 
class Continue(Node):
	def __init__(self):
		pass
 
class WhileInstr(Node):
    def __init__(self,condition,instruction):
        self.condition=condition
        self.instruction=instruction
        
class RepeatInstr(Node):
    def __init__(self,instructions,condition):
        self.instructions=instructions
        self.condition=condition

class ReturnInstr(Node):
    def __init__(self,expression):
        self.expression=expression

class Integer(Node):
    def __init__(self,value,line):
        self.value=value
        self.line=line

class Float(Node):
    def __init__(self,value,line):
        self.value=value
        self.line=line
    
class String(Node):
    def __init__(self,value,line):
        self.value=value
        self.line=line

class Id(Node):
    def __init__(self,value,line):
        self.value=value
        self.line=line
# ...


