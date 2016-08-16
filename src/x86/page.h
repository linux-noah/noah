#define PTE_P           0x001   // Present
#define PTE_W           0x002   // Writeable
#define PTE_U           0x004   // User
#define PTE_PS          0x080   // Page Size

#define CR0_PE          0x00000001      // Protection Enable
#define CR0_NE          0x00000020      // Numeric Error Enable
#define CR0_PG          0x80000000      // Paging
#define CR4_PSE         0x00000010      // Page size extension
#define CR4_PAE         0x00000020      
#define CR4_OSFXSR      0x00000200
#define CR4_VMXE        0x00002000      

#define EFER_LME        0x00000100      // Lond Mode Enable
#define EFER_LMA        0x00000400      // Lond Mode Active
