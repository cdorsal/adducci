// Includes
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/hrtimer.h>

// Defines
#define MODULE_AUTH     "Craig Allen Dorsey"
#define MODULE_DESC     "Adducci, A High Resolution Timer Kernel Module"
#define MODULE_LIC      "Dual MIT/GPL"
#define TIMER_PERIOD_MS 100

// Globals
static struct hrtimer htimer;
static ktime_t kt_period;

// Module Information
MODULE_LICENSE(MODULE_LIC);
MODULE_AUTHOR(MODULE_AUTH);
MODULE_DESCRIPTION(MODULE_DESC);

// Timer Callback
static enum hrtimer_restart timerCallback(struct hrtimer * timer)
{
    // TODO: Add a task for this callback

    // Forward the timer
    hrtimer_forward_now(timer, kt_period);
    return HRTIMER_RESTART;
}

// Module Init
static int __init timerInit(void)
{
    printk(KERN_INFO "Loading High Resolution Timer Module\n");

    // Set the kernel timer period
    kt_period = ktime_set(0, (TIMER_PERIOD_MS * 1E6L)); // seconds, nanoseconds

    // Initialize the kernel timer
    hrtimer_init(&htimer, CLOCK_REALTIME, HRTIMER_MODE_REL);

    // Set the timer handler function
    htimer.function = timerCallback;

    return 0;
}

// Module Exit
static void __exit timerExit(void)
{
    printk(KERN_INFO "Unloading High Resolution Timer Module\n");

    // Kill the kernel timer
    hrtimer_cancel(&htimer);
}

module_init(timerInit);
module_exit(timerExit);
