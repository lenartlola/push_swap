Nah, it isn't! push_swap is not really strange.

Unlike the other posts, I won't walk-through presenting
the project. I know if you're interested in this repository
in any way, so it is for obvious reasons, and you know well
the problem.

Used data structure, doubly linked list.

```
     ┌────────────────┐
┌────┤  t_node *top   │
│    ├────────────────┤
│    │    int size    │
│    ├────────────────┤
│    │ t_node *bottom ├────────────────────────────────────────────┐
│    └────────────────┘                                            │
│     t_node *bottom                                               │
│                                                                  │
│                                                                  │
│ NULL                                                             │
│  ▲  ┌──────────────┐      ┌──────────────┐     ┌──────────────┐  │
│  └──┤ t_node *prev │  ┌───┤ t_node *prev │ ┌───┤ t_node *prev │  │
│     ├──────────────┤  │   ├──────────────┤ │   └──────────────┤  │
└────►│   int value  │◄─┘ ┌►│   int size   │◄┘ ┌─►   int size   │◄─┘
      ├──────────────┤    │ ├──────────────┤   │ ┌──────────────┤
      │ t_node *next ├────┘ │ t_node *next ├───┘ │ t_node *next ├─┐
      └──────────────┘      └──────────────┘     └──────────────┘ │
                                                                  ▼
                                                                NULL
```                                                       


